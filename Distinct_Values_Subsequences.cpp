// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n;
map<int,int> mp;

signed main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }

    int ans=1;
    for(auto [a,b]:mp){
        ans=(ans*(b+1))%MOD;
    }
    ans=(ans+MOD-1)%MOD;

    cout<<ans<<endl;
}
