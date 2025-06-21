// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=998244353;
///////////////////////////////////////////////////////////
int n,k;
tuple<int,int> dp[69][69][2];

inline constexpr auto bit=[](int x,int y){return x&(1LL<<y);};

inline tuple<int,int> f(int b=61, int left=k, bool x=1){
    if(left==0)return {1,0};
    if(b==-1)return {0,0};
    if(dp[b][left][x] != tuple<int,int>{-1,-1})return dp[b][left][x];

    auto [cnt0,ans0] = f(b-1,left,x&&!bit(n,b));
    auto [cnt1,ans1] = x && !bit(n,b) ? tuple<int,int>(0,0) : f(b-1,left-1,x);

    return dp[b][left][x] = {(cnt0 + cnt1)%MOD, (ans0 + ans1 + cnt1 * ((1LL<<b) % MOD))%MOD};
}

inline void solve(void){
    for(int i=0;i<69;i++)
        for(int j=0;j<69;j++)
            dp[i][j][0]=dp[i][j][1]={-1,-1};

    cin>>n>>k;
    auto [cnt,ans]=f();
    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
