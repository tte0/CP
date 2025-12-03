// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt")
namespace h{
/*
23 SOFTWARE LICENSE 2.1

Copyright © 2025 Ahmet Emre Gürdal

This is anti-capitalist software, released for free use by individuals and organizations that do not operate by capitalist principles.

Permission is hereby granted, free of charge, to any person or organization (the "User") obtaining a copy of this software and associated documentation files (the "Software"), to use, copy, modify, merge, distribute, and/or sell copies of the Software, subject to the following conditions:

1. The above copyright notice and this permission notice shall be included in all copies or modified versions of the Software.

2. The User is one of the following:
a. An individual person, laboring for themselves
b. A non-profit organization
c. An educational institution
d. An organization that seeks shared profit for all of its members, and allows non-members to set the cost of their labor

3. If the User is an organization with owners, then all owners are workers and all workers are owners with equal equity and/or equal vote.

4. If the User is an organization, then the User is not law enforcement or military, or working for or under either.

5. The User will not include the number that equates to 36 + 1 in any copies or modified versions of this Software.

6. The User will not use this Software for evil purposes.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

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

template <typename Key, typename Value, typename Hasher = RandomizedHasher>
class HashMap {
public:
  class alignas(8) m_Slot {
  public:
    Key key;
    Value val;
    std::uint8_t dfh; // distance from home
    inline void swap(m_Slot &slot) {
      std::swap(this->key, slot.key);
      std::swap(this->val, slot.val);
      this->dfh ^= slot.dfh;
      slot.dfh ^= this->dfh;
      this->dfh ^= slot.dfh;
    }

    using pairType = std::pair<const Key, Value>;
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
    using value_type = typename m_Slot::pairType;
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
  inline void insertElement(Key const &key, Value const &value) {
    if (m_size >= ((m_table.size()) * 8) / 10 || m_maxDfh >= m_MAX_DFH_LIM) {
      rehash();
    }

    m_Slot currentEntry;
    currentEntry.key = key;
    currentEntry.val = value;
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
        insertElement(std::move(oldSlot.key), std::move(oldSlot.val));
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
  inline HashMap(std::size_t initialCapacity = 8) {
    initializeTable(initialCapacity);
  }

  inline void insert(std::pair<Key, Value> slot) {
    if (findIndex(slot.first) == SIZE_MAX)
      insertElement(slot.first, slot.second);
  }

  inline void emplace(Key const &key, Value const &val) {
    insert(std::make_pair(key, val));
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
      m_table[i].val = std::move(m_table[nexti].val);
      m_table[i].dfh = m_table[nexti].dfh - 1;
      m_table[nexti].dfh = m_EMPTY_SLOT_DFH;

      i = nexti;
      nexti = nextIndex(i);
    }

    return true;
  }

  inline Value &at(Key const &key) {
    std::size_t i = findIndex(key);
    if (i == SIZE_MAX)
      throw std::out_of_range("Key not found in HashMap::at()");

    return m_table[i].val;
  }

  inline Value &operator[](Key const &key) {
    std::size_t i = findIndex(key);
    if (i != SIZE_MAX)
      return m_table[i].val;

    insertElement(key, Value{});
    i = findIndex(key);
    return m_table[i].val;
  }

  inline Iterator begin() { return Iterator(m_table.begin(), m_table.end()); }
  inline Iterator end() { return Iterator(m_table.end(), m_table.end()); }

  inline bool contains(Key const &key) const {
    return findIndex(key) != SIZE_MAX;
  }
  inline bool empty() const { return m_size == 0; }

  inline void clear(std::size_t newCapacity = 8) { initializeTable(8); }

  inline void swap(HashMap &other) noexcept {
    using std::swap;
    swap(m_table, other.m_table);
    swap(m_size, other.m_size);
    swap(m_capacityMask, other.m_capacityMask);
    swap(m_hasher, other.m_hasher);
  }
};
}
using namespace std;
///////////////////////////////////////////////////////////
int64_t n;
int arr[5];
int64_t ans;


constexpr uint64_t rotl64(uint64_t x, uint64_t r) {
    return (x << r) | (x >> (64 - r));
}

template<typename... Ints>
constexpr uint64_t has(Ints... args) {
    uint64_t hash = 0xcbf29ce484222325ull; // 64-bit FNV offset basis
    ((hash ^= static_cast<uint64_t>(args) + 0x9e3779b97f4a7c15ull + rotl64(hash, 31) + (hash >> 3)), ...);
    return hash;
}


signed main(void){
    h::HashMap<uint64_t,int64_t> mp,mp2,mp3,mp4,mp5;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef LOCAL
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    #endif

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4];
        sort(arr,arr+5);

        ans+=mp[arr[0]]++;
        ans+=mp[arr[1]]++;
        ans+=mp[arr[2]]++;
        ans+=mp[arr[3]]++;
        ans+=mp[arr[4]]++;
        //cerr<<ans<<endl;

        ans-=mp2[has(arr[0],arr[1])]++;
        ans-=mp2[has(arr[0],arr[2])]++;
        ans-=mp2[has(arr[0],arr[3])]++;
        ans-=mp2[has(arr[0],arr[4])]++;
        ans-=mp2[has(arr[1],arr[2])]++;
        ans-=mp2[has(arr[1],arr[3])]++;
        ans-=mp2[has(arr[1],arr[4])]++;
        ans-=mp2[has(arr[2],arr[3])]++;
        ans-=mp2[has(arr[2],arr[4])]++;
        ans-=mp2[has(arr[3],arr[4])]++;
        //cerr<<ans<<endl;

        ans+=mp3[has(arr[0],arr[1],arr[2])]++;
        ans+=mp3[has(arr[0],arr[1],arr[3])]++;
        ans+=mp3[has(arr[0],arr[1],arr[4])]++;
        ans+=mp3[has(arr[0],arr[2],arr[3])]++;
        ans+=mp3[has(arr[0],arr[2],arr[4])]++;
        ans+=mp3[has(arr[0],arr[3],arr[4])]++;
        ans+=mp3[has(arr[1],arr[2],arr[3])]++;
        ans+=mp3[has(arr[1],arr[2],arr[4])]++;
        ans+=mp3[has(arr[1],arr[3],arr[4])]++;
        ans+=mp3[has(arr[2],arr[3],arr[4])]++;
        //cerr<<ans<<endl;

        ans-=mp4[has(arr[0],arr[1],arr[2],arr[3])]++;
        ans-=mp4[has(arr[0],arr[1],arr[2],arr[4])]++;
        ans-=mp4[has(arr[0],arr[1],arr[3],arr[4])]++;
        ans-=mp4[has(arr[0],arr[2],arr[3],arr[4])]++;
        ans-=mp4[has(arr[1],arr[2],arr[3],arr[4])]++;
        //cerr<<ans<<endl;

        ans+=mp5[has(arr[0],arr[1],arr[2],arr[3],arr[4])]++;
        //cerr<<ans<<endl;
        //cerr<<"-------------"<<endl;
    }

    cout<<(n*(n-1))/2-ans<<endl;
    
}
