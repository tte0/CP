// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1000;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int q,mp[N+1];

signed main(void){
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        for(int i=x;i<=y;i++)mp[i]++;
        int ans=0;
        for(int i=1;i<=N;i++){
            ans+=(((i*mp[i])%MOD)*mp[i])%MOD;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }    
}
