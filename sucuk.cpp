#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt")
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;

inline constexpr int binpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1)
      ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

inline constexpr int modrev(int a) { return binpow(a, MOD - 2); }


inline constexpr auto get_pref(){
    array<int,50*50+1> pref{};
    pref[0]=pref[1]=1;
    for (int i = 2; i <= 50 * 50; i++) {
        pref[i] = (pref[i - 1] * i) % MOD;
    }
    return pref;
}
inline constexpr auto get_comb(){
    array<array<int,51>,51> comb{};
    for (int i = 0; i <= 50; i++)
        comb[i][0] = 1;

    for (int i = 1; i <= 50; i++) {
        for (int j = i; j <= 50; j++) {
            comb[j][i] = (((comb[j][i - 1] * (j - i + 1)) % MOD) * modrev(i)) % MOD;
        }
    }
    return comb;
}
constexpr array<int,50*50+1> pref=get_pref();
inline constexpr auto get_ipref(){
    array<int,50*50+1> ipref{};
    for(int i=0;i<50*50+1;i++)ipref[i]=modrev(pref[i]);
    return ipref;
}
constexpr array<int,50*50+1> ipref=get_ipref();
constexpr array<array<int,51>,51> comb=get_comb();c

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  vector<int> dp(n * 50 + 1, 0);
  dp[0] = 1;




  for (int i = 0; i < n; i++) {
    vector<int> dpnew(n * 50 + 1, 0);

    for (int j = 0; j < a[i]; j++) {
      for (int k = j + 1; k <= n * 50; k++) {
        int cur = comb[a[i] - 1][j] * dp[k - j - 1] % MOD;
        cur = (cur * (pref[k])) % MOD;
        cur = (cur * ipref[k - j - 1]) % MOD;

        cur = (cur * ipref[j + 1]) % MOD;

        // for (int l = 1; l <= j + 1; l++) {
        //   cur = (cur * (k - j - 1 + l)) % MOD;
        //   cur = (cur * modrev(l)) % MOD;
        // }
        dpnew[k] = (dpnew[k] + cur);
        if (dpnew[k] > MOD)
          dpnew[k] -= MOD;
      }
    }
    swap(dpnew, dp);
  }

  for (int i = 1; i <= n * 50; i++) {
    dp[i] = (dp[i] + dp[i - 1]) % MOD;
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = (dp[r] - dp[l - 1]);
    if (ans < 0)
      ans += MOD;
    cout << ans << '\n';
  }
}