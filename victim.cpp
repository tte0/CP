#include <bits/stdc++.h>
#define FOR(i, j, n) for (int i = static_cast<int>(j); i < static_cast<int>(n); ++i)
#define ROF(i, j, n) for (int i = static_cast<int>(n) - 1; i >= static_cast<int>(j); --i)
#define BADSEED random_device{}()
using namespace std;
 
template <class T, class AddT, class MultT, T P>
struct ModNum {
    T val = 0;
    constexpr ModNum() = default;
    constexpr ModNum(T x) : val(x) {}
    template <class S>
    static constexpr ModNum Safe(S x) {
        return static_cast<T>(((x % P) + P) % P);
    }
    explicit constexpr operator T() const { return val; }
 
    constexpr bool operator==(ModNum rhs) const { return val == rhs.val; }
    constexpr bool operator!=(ModNum rhs) const { return val != rhs.val; }
    constexpr ModNum operator-() const { return (val == 0) ? (*this) : (P - val); }
 
    constexpr ModNum& operator+=(ModNum rhs) { return *this = Add(val, rhs.val); }
    constexpr ModNum& operator-=(ModNum rhs) { return *this = Sub(val, rhs.val); }
    constexpr ModNum& operator*=(ModNum rhs) { return *this = Mult(val, rhs.val); }
    constexpr ModNum& operator/=(ModNum rhs) { return *this *= rhs.Inverse(); }
 
    template <class S>
    constexpr ModNum Pow(S ex) const {
        if (P == 1) return 0;
        if (ex < 0) return Pow(-ex).Inverse();
        ModNum result = 1;
        ModNum base(*this);
        while (ex > 0) {
            if (ex & 1) result *= base;
            ex >>= 1;
            base *= base;
        }
        return result;
    }
    constexpr ModNum Inverse() const { return Pow(P - 2); }
    friend constexpr ModNum operator+(ModNum lhs, ModNum rhs) { return Add(lhs.val, rhs.val); }
    friend constexpr ModNum operator-(ModNum lhs, ModNum rhs) { return Sub(lhs.val, rhs.val); }
    friend constexpr ModNum operator*(ModNum lhs, ModNum rhs) { return Mult(lhs.val, rhs.val); }
    friend constexpr ModNum operator/(ModNum lhs, ModNum rhs) { return lhs * rhs.Inverse(); }
 
   private:
    static constexpr T Add(AddT lhs, AddT rhs) {
        auto sum = lhs + rhs;
        return (sum < P) ? sum : (sum - P);
    }
    static constexpr T Sub(AddT lhs, AddT rhs) {
        auto dif = lhs - rhs;
        return (dif >= 0) ? dif : (dif + P);
    }
    static constexpr T Mult(MultT lhs, MultT rhs) { return static_cast<T>((lhs * rhs) % P); }
    friend std::ostream& operator<<(std::ostream& os, ModNum m) { return os << m.val; }
    friend std::istream& operator>>(std::istream& is, ModNum& m) {
        is >> m.val;
        return is;
    }
};
using Num = ModNum<int, int, long long, 1000000007>;
 
 
 
namespace narut {
	template <int M> using HashNum = ModNum<int, int, int64_t, M>;
	template <class T, int... Mod> struct RollingHash {
		vector<T> data;
		tuple<vector<HashNum<Mod>>...> hashes;
		static const tuple<HashNum<Mod>...> bases;
		static tuple<vector<HashNum<Mod>>...> base_pows;
 
		struct HashView {
			int l, r;
			RollingHash const *H;
			T const &operator[](int i) const { return H->data[l + i]; }
			auto ToStringView() const { return basic_string_view<T>(&H->data[l], r - l); }
			auto Hash() const { return H->HashRange(l, r); }
			int Length() const { return r - l; }
			bool operator==(HashView const &rhs) const {
				if (r - l != rhs.r - rhs.l) return false;
				return Hash() == rhs.Hash();
			}
			bool operator!=(HashView const &rhs) const { return !(*this == rhs); }
			bool operator<(HashView const &rhs) const { return StrCmp(*this, rhs) < 0; }
			bool operator<=(HashView const &rhs) const { return StrCmp(*this, rhs) <= 0; }
			bool operator>(HashView const &rhs) const { return StrCmp(*this, rhs) > 0; }
			bool operator>=(HashView const &rhs) const { return StrCmp(*this, rhs) >= 0; }
		};
 
		RollingHash() = default;
 
		template <class It>
		RollingHash(It first, It last)
			: data(first, last), hashes(make_hashes(make_index_sequence<sizeof...(Mod)>{})) {
			extend_base_pows(data.size(), make_index_sequence<sizeof...(Mod)>{});
		}
 
		// [l, r)
		auto HashRange(int l, int r) const {
			return hash_range(l, r, make_index_sequence<sizeof...(Mod)>{});
		}
 
		auto SubStr(int pos, int len) const { return HashView{pos, pos + len, this}; }
 
		static int FirstDiffer(HashView const &a, HashView const &b) {
			int lo = 1, hi = min(a.r - a.l, b.r - b.l) + 1;
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (a.H->HashRange(a.l, a.l + mid) == b.H->HashRange(b.l, b.l + mid))
					lo = mid + 1;
				else
					hi = mid;
			}
			return lo - 1;
		}
 
		// a == b => 0, a < b => -1, a > b => 1
		static int StrCmp(HashView const &a, HashView const &b) {
			int dif = FirstDiffer(a, b);
			if (dif == a.Length()) {
				if (dif == b.Length()) return 0;
				return -1;
			}
			if (dif == b.Length()) return 1;
			if (a[dif] < b[dif]) return -1;
			if (a[dif] > b[dif]) return 1;
			return 0;
		}
 
	  private:
		template <size_t... Is> auto hash_range(int l, int r, index_sequence<Is...>) const {
			return make_tuple(
				(get<Is>(hashes)[r] - get<Is>(base_pows)[r - l] * get<Is>(hashes)[l])...);
		}
		template <int M> auto make_hash(HashNum<M> base) {
			vector<HashNum<M>> hash(data.size() + 1);
			for (uint i = 0; i < data.size(); ++i) hash[i + 1] = base * hash[i] + data[i];
			return hash;
		}
		template <size_t... Is> auto make_hashes(index_sequence<Is...>) {
			return make_tuple(make_hash<Mod>(get<Is>(bases))...);
		}
 
		template <size_t I> static void extend_base_pow(int sz) {
			auto &v = get<I>(base_pows);
			int old_sz = v.size();
			if (old_sz < sz) {
				v.resize(sz, 1);
				for (int i = max(old_sz, 1); i < sz; ++i) v[i] = get<I>(bases) * v[i - 1];
			}
		}
		template <size_t... Is> static void extend_base_pows(int sz, index_sequence<Is...>) {
			(extend_base_pow<Is>(sz + 1), ...);
		}
		static auto make_bases() {
			mt19937 rng(BADSEED);
			return tuple<HashNum<Mod>...>{uniform_int_distribution<int>(27, Mod - 1)(rng)...};
		}
	};
	template <class T, int... Mod>
	const tuple<HashNum<Mod>...>
		RollingHash<T, Mod...>::bases = RollingHash<T, Mod...>::make_bases();
	template <class T, int... Mod> tuple<vector<HashNum<Mod>>...> RollingHash<T, Mod...>::base_pows;
} // namespace narut
 
using RH = narut::RollingHash<char, (int)1e9 + 7, (int)1e6 + 3>;
 
 
void Run() {
	string s, p;
	cin>>s>>p;
 
	int n = s.length(), m = p.length();
 
	RH S(begin(s), end(s));
	RH P(begin(p), end(p));
 
	auto pp = P.SubStr(0, m);
	int ans = 0;
	FOR(i, 0, n-m+1) {
		if (S.SubStr(i, m) == pp) ans++;		
	}	
	cout << ans;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(10);
#ifdef NARUT_LOCAL
	cerr << fixed << setprecision(10);
	assert(freopen("./io/test.in", "r", stdin));
	// assert(freopen("./io/test.out", "w", stdout));
#endif
 
	Run();
}