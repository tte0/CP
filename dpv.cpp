// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
///////////////////////////////////////////////////////////
int n,MOD,x,y,dp[N],a[N];
vector<int> adj[N];

inline int dfs(int node=0,int p=-1){
    a[node]=1;
    for(int i:adj[node]){
        if(i==p)continue;
        a[node]=a[node]*(dfs(i,node)+1)%MOD;
    }
    return a[node];
}

inline void f(int node=0,int p=-1,int b=1){
    // cerr<<"b["<<node<<"]:"<<b<<endl;
    dp[node]=a[node]*b%MOD;
    vector<int> pre,suf;

    pre.push_back(1);suf.push_back(1);
    for(int i:adj[node]){
        if(i==p)continue;
        pre.push_back(a[i]+1);
        suf.push_back(a[i]+1);
    }
    pre.push_back(1);suf.push_back(1);

    // cerr<<"pre: ";for(auto i:pre)cerr<<i<<",";
    // cerr<<endl;
    // cerr<<"suf: ";for(auto i:suf)cerr<<i<<",";
    // cerr<<endl;

    for(int i=2;i<pre.size()-1;i++)pre[i]=pre[i-1]*pre[i]%MOD;
    for(int i=suf.size()-3;i>0;i--)suf[i]=suf[i]*suf[i+1]%MOD;
    

    // cerr<<"pre: ";for(auto i:pre)cerr<<i<<",";
    // cerr<<endl;
    // cerr<<"suf: ";for(auto i:suf)cerr<<i<<",";
    // cerr<<endl;
    
    int ind=1;
    for(int i:adj[node]){
        if(i==p)continue;
        int x=((pre[ind-1]*suf[ind+1]%MOD)*b+1)%MOD;
        f(i,node,x);
        ind++;
    }
}

signed main(void){
    cin>>n>>MOD;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    

    dfs();
    f();
    
    // for(int i=0;i<n;i++)cerr<<"a["<<i<<"]:"<<a[i]<<endl;
    for(int i=0;i<n;i++)cout<<dp[i]<<endl;

}

