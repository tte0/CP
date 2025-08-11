// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k,b;
vector<int> v;
vector<vector<int>> dp;

inline bool __f(int w){
    dp.assign(n+2,vector<int>(b+2,1e9));
    dp[0][0]=0;

    for(int i=0;i<n;i++){
        int it_k=lower_bound(v.begin(),v.end(),v[i]+w)-v.begin();
        int it_b=lower_bound(v.begin(),v.end(),v[i]+2*w)-v.begin();

        for(int j=0;j<=b;j++){
            dp[it_k][j]=min(dp[it_k][j],dp[i][j]+1);
            dp[it_b][j+1]=min(dp[it_b][j+1],dp[i][j]);
        }
    }

    /*cerr<<"w:"<<w<<endl;
    for(auto t:dp){
        cerr<<"dp:";
        for(auto i:t)cerr<<i<<",";
        cerr<<endl;
    }cerr<<endl;*/

    for(int j=0;j<=b;j++)if(dp[n][j]<=k)return true;
    return false;
}

signed main(void){
    cin>>n>>k>>b;
    v.resize(n);
    for(auto& i:v)cin>>i;

    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    n=v.size();
    b=min(n,b);
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;

    int l=1,r=1e9;
    while(l<r){
        int m=(l+r)>>1;
        if(!__f(m))l=m+1;
        else r=m;
    }

    cout<<l<<endl;
}
