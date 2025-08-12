// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=998244353;
///////////////////////////////////////////////////////////
int n,m;
vector<vector<int>> dp(64,vector<int>(64,0));

signed main(void){
    cin>>n>>m;
    dp[0][0]=1;
    if(n>61){
        cout<<"0\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        int sum=dp[i-1][0];
        for(int j=1;j<=__lg(m);j++){
            dp[i][j]=(sum*((int(1)<<(j-1))%MOD))%MOD;
            sum+=dp[i-1][j];
            sum%=MOD;
        }
        dp[i][__lg(m)+1]=(sum*((m-(int(1)<<__lg(m))+1)%MOD))%MOD;
    }

    int ans=0;
    for(int j=0;j<64;j++){
        ans+=dp[n][j];
        ans%=MOD;
    }

    cout<<ans<<endl;
}
