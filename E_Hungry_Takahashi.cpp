// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m;
vector<vector<int>> v,dp;
vector<int> p;

inline bool f(int x){
    vector<vector<int>> dp(n,vector<int>(m,-1e18));
    dp[0][0]=x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]+=v[i][j]-p[i+j];
            if(dp[i][j]<0)continue;
            if(i<n-1)dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j<m-1)dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
        }
    }
    
    return dp[n-1][m-1]>=0;
}

signed main(void){
    cin>>n>>m;
    v.resize(n,vector<int>(m));
    dp.assign(n,vector<int>(m,-1e18));
    p.resize(n+m-1);
    for(auto& t:v)for(auto& i:t)cin>>i;
    for(auto& i:p)cin>>i;

    int l=0,r=1e18;
    while(l<r){
        int m=(l+r)/2;
        if(!f(m))l=m+1;
        else r=m;
    }

    cout<<l<<endl;
}
