// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#pragma GCC target("avx2,popcnt")
#define int int_fast64_t
using namespace std;
constexpr size_t N=4e5+5;
///////////////////////////////////////////////////////////
int n,sieve[N];
vector<int> v;

inline void sieve(){
    for(int i=4;i<N;i++)
}

inline void solve(){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
}

signed main(void){
    sieve();
    int t;
    cin>>t;
    while(t--)solve();
}
