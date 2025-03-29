// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
static constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,root,ans,dp[N][2];
bitset<N> vis;
vector<int> a,c,adj[N],bt;

inline void f(int node){
    bt.push_back(node);
    dp[node][1]=c[node];
    for(auto i:adj[node]){
        if(i==root)continue;
        f(i);
        dp[node][0]+=dp[i][1];
        dp[node][1]+=min(dp[i][0],dp[i][1]);
    }
}

signed main(void){
    cin>>n;
    a.resize(n);    
    c.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:c)cin>>i;

    for(int i=0;i<n;i++){
        if(i!=--a[i])adj[a[i]].push_back(i);
        else c[i]=0;
    }

    for(int i=0;i<n;i++){
        if(vis[i])continue;
        //cerr<<"going "<<i<<endl;
        int l=i,r=a[i];
        while(l!=r){
            l=a[l];
            r=a[a[r]];
        }

        root=l;
        f(root);
        int t=dp[root][1];
        //cerr<<"root1: "<<root<<endl;
        //cerr<<"dp: ";for(int i=0;i<n;i++)//cerr<<dp[i][0]<<",";//cerr<<endl;
        //cerr<<"dp: ";for(int i=0;i<n;i++)//cerr<<dp[i][1]<<",";//cerr<<endl;

        for(auto i:bt)dp[i][0]=dp[i][1]=0;

        root=a[root];
        f(root);
        t=min(t,dp[root][1]);
        //cerr<<"root2: "<<root<<endl;
        //cerr<<"dp: ";for(int i=0;i<n;i++)//cerr<<dp[i][0]<<",";//cerr<<endl;
        //cerr<<"dp: ";for(int i=0;i<n;i++)//cerr<<dp[i][1]<<",";//cerr<<endl;

        ans+=t;

        //cerr<<"visited: ";for(auto i:bt)//cerr<<i<<",";//cerr<<endl;
        //cerr<<"ans: "<<ans<<endl;

        for(auto i:bt)vis[i]=true;
        bt.clear();
        //cerr<<endl;
    }

    cout<<ans<<endl;
}
