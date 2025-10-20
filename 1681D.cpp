// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h> 

//////////////////////////////////////
#include <cstdint>
#include <random>
#include <type_traits>
#include <utility>

static std::random_device g_rd;
static std::mt19937_64 g_rng(g_rd());
class RandomizedHasher {
private:
  static constexpr long double m_PI = 3.14159265358979323846264;
  static constexpr std::uint64_t m_C =
      static_cast<std::uint64_t>(2000000000000000000 * m_PI) + 23;
  const std::uint64_t m_RANDOM = g_rng();

public:
  template <typename T, typename = std::enable_if_t<std::is_integral_v<T> &&
                                                    (sizeof(T) <= 8)>>
  inline std::size_t operator()(T const &x) const {
    return __builtin_bswap64((static_cast<std::uint64_t>(x) ^ m_RANDOM) * m_C);
  }

  template <typename T1, typename T2>
  inline std::size_t operator()(std::pair<T1, T2> const &x) {
    return __builtin_bswap64(this->operator()(x.first) ^
                             (this->operator()(x.second) + m_C));
  }
};

#include <algorithm>

template <typename Key, typename Hasher = RandomizedHasher> class HashSet {
public:
  class alignas(8) m_Slot {
  public:
    Key key;
    std::uint8_t dfh; // distance from home
    inline void swap(m_Slot &slot) {
      std::swap(this->key, slot.key);
      this->dfh ^= slot.dfh;
      slot.dfh ^= this->dfh;
      this->dfh ^= slot.dfh;
    }
  };

  class Iterator {
  private:
    using SlotVectorIterator = typename std::vector<m_Slot>::iterator;
    SlotVectorIterator m_it;
    SlotVectorIterator m_end;
    static constexpr uint8_t EMPTY_DFH = 0xFF;

    inline void skipEmpty() {
      while (m_it != m_end && m_it->dfh == EMPTY_DFH)
        ++m_it;
    }

  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = Key;
    using difference_value = std::ptrdiff_t;
    using pointer = value_type *;
    using reference = value_type &;

    Iterator(SlotVectorIterator current, SlotVectorIterator end)
        : m_it(current), m_end(end) {
      skipEmpty();
    }

    reference operator*() const {
      return *reinterpret_cast<pointer>(&m_it->key);
    }

    Iterator &operator++() {
      ++m_it;
      skipEmpty();
      return *this;
    }

    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    bool operator==(const Iterator &other) const { return m_it == other.m_it; }
    bool operator!=(const Iterator &other) const { return m_it != other.m_it; }
  };

private:
  static constexpr std::uint8_t m_MAX_DFH_LIM = 32;

  std::vector<m_Slot> m_table;

  std::size_t m_size = 0;
  std::size_t m_capacityMask = 0;
  std::uint8_t m_maxDfh = 0;
  Hasher m_hasher;
  static constexpr std::uint8_t m_EMPTY_SLOT_DFH = 0xFF;

  inline std::size_t getHomeIndex(Key const &key) const {
    return m_hasher(key) & m_capacityMask;
  }

  inline std::size_t nextIndex(std::size_t i) const {
    return (i + 1) & m_capacityMask;
  }
  inline void insertElement(Key const &key) {
    if (m_size >= ((m_table.size()) * 8) / 10 || m_maxDfh >= m_MAX_DFH_LIM) {
      rehash();
    }

    m_Slot currentEntry;
    currentEntry.key = key;
    currentEntry.dfh = 0;

    std::size_t i = getHomeIndex(key);

    while (true) {
      m_Slot &slot = m_table[i];
      if (slot.dfh == m_EMPTY_SLOT_DFH) {
        m_maxDfh = std::max(m_maxDfh, currentEntry.dfh);
        slot.swap(currentEntry);
        m_size++;
        return;
      }

      if (currentEntry.dfh > slot.dfh) {
        slot.swap(currentEntry);
        m_maxDfh = std::max(m_maxDfh, currentEntry.dfh);
      }

      currentEntry.dfh++;
      i = nextIndex(i);
    }
  }

  inline void rehash() {
    std::size_t oldCapacity = m_table.size();
    std::size_t newCapacity = oldCapacity << 1;

    std::vector<m_Slot> oldTable = std::move(m_table);
    m_table.resize(newCapacity);
    m_capacityMask = newCapacity - 1;
    m_size = 0;
    m_maxDfh = 0;

    for (auto &slot : m_table)
      slot.dfh = m_EMPTY_SLOT_DFH;

    for (auto &oldSlot : oldTable) {
      if (oldSlot.dfh != m_EMPTY_SLOT_DFH) {
        insertElement(std::move(oldSlot.key));
      }
    }
  }

  inline std::size_t findIndex(Key const &key) const {
    std::size_t i = getHomeIndex(key);
    std::uint8_t dfhCur = 0;

    while (m_table[i].dfh != m_EMPTY_SLOT_DFH) {
      if (m_table[i].dfh < dfhCur)
        return SIZE_MAX;
      if (m_table[i].dfh == dfhCur && m_table[i].key == key)
        return i;

      dfhCur++;
      i = nextIndex(i);
    }

    return SIZE_MAX;
  }

public:
#pragma GCC target("popcnt,lzcnt")
  inline void initializeTable(std::size_t initialCapacity) {
    if (__builtin_popcountll(initialCapacity) > 1)
      initialCapacity = (1ull << (64 - __builtin_clzll(initialCapacity)));
    m_table.resize(initialCapacity);
    m_capacityMask = initialCapacity - 1;
    m_size = 0;
    m_maxDfh = 0;

    for (auto &slot : m_table) {
      slot.dfh = m_EMPTY_SLOT_DFH;
    }
  }
  inline HashSet(std::size_t initialCapacity = 8) {
    initializeTable(initialCapacity);
  }

  inline void insert(Key slot) {
    if (findIndex(slot) == SIZE_MAX)
      insertElement(slot);
  }

  inline size_t size() const noexcept { return m_size; }

  inline bool erase(Key const &key) {
    std::size_t i = findIndex(key);
    if (i == SIZE_MAX)
      return false;

    m_table[i].dfh = m_EMPTY_SLOT_DFH;
    m_size--;

    std::size_t nexti = nextIndex(i);

    while (m_table[nexti].dfh > 0) {
      m_table[i].key = std::move(m_table[nexti].key);
      m_table[i].dfh = m_table[nexti].dfh - 1;
      m_table[nexti].dfh = m_EMPTY_SLOT_DFH;

      i = nexti;
      nexti = nextIndex(i);
    }

    return true;
  }

  inline Iterator begin() { return Iterator(m_table.begin(), m_table.end()); }
  inline Iterator end() { return Iterator(m_table.end(), m_table.end()); }

  inline bool contains(Key const &key) const {
    return findIndex(key) != SIZE_MAX;
  }
  inline bool empty() const { return m_size == 0; }

  inline void clear(std::size_t newCapacity = 8) { initializeTable(8); }

  inline void swap(HashSet &other) noexcept {
    using std::swap;
    swap(m_table, other.m_table);
    swap(m_size, other.m_size);
    swap(m_capacityMask, other.m_capacityMask);
    swap(m_hasher, other.m_hasher);
  }
};

/////////////////////////////////////

#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,x;
queue<tuple<int,int>> q;
HashSet<int> st;

inline vector<int> f(int x){
    vector<int> v;
    int t=x;
    while(t){
        if(t%10>1)v.push_back(x*(t%10));
        t/=10;
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    return v;
}

inline int digit(int x){
    int cnt=0;
    while(x){
        cnt++;
        x/=10;
    }
    return cnt;
}

signed main(void){
    cin>>n>>x;

    q.push({0,x});
    st.insert(x);
    while(q.size()){
        auto [d,x]=q.front();q.pop();
        if(digit(x)==n){
            cout<<d<<endl;
            exit(0);
        }
        vector<int> possible=f(x);
        for(auto i:possible){
            if(!st.contains(i)){
                q.push({d+1,i});
                st.insert(i);
            }
        }
    }

    cout<<"-1\n";
}
