#pragma GCC target("popcnt,avx,avx2")
#pragma GCC optimize("unroll-loops,no-stack-protector,O3,fast-math")
// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m,dp[1<<18+1];
vector<int> x,y,z,a;
vector<tuple<int,int,int>> v;

inline bool check(int b){
    int cnt=__builtin_popcount(b);
    for(int i=a[cnt];i<a[cnt+1];i++){
        int x=b;
        x&=(1<<y[i])-1;
        if(__builtin_popcount(x)>z[i])return false;
    }
    return true;
}

inline int f(int b){
    if(dp[b]!=-1)return dp[b];
    if(!check(b))return dp[b]=0;
    if(b==(1<<n)-1)return dp[b]=1;
    dp[b]=0;
    for(int i=0;i<n;i++){
        if(b&(1<<i))continue;
        dp[b]+=f(b|(1<<i));
    }
    return dp[b];
}

signed main(void){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    a.resize(n+2,m);
    v.resize(m);
    for(auto& [x,y,z]:v){
        cin>>x>>y>>z;
    }
    sort(v.begin(),v.end());
    for(auto [a,b,c]:v){
        x.push_back(a);
        y.push_back(b);
        z.push_back(c);
    }

    for(int i=0;i<m;i++){
        a[x[i]]=min(a[x[i]],i);
    }
    for(int i=n-1;i>=0;i--)a[i]=min(a[i],a[i+1]);
    // cerr<<"a:";for(auto i:a)cerr<<i<<",";cerr<<endl;
    
    cout<<f(0)<<endl;

}

