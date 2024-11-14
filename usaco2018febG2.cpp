// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
///////////////////////////////////////////////////////////
int n,x,cnt,sz[N],a[N],dp[N];
string s;
vector<int> adj[N],c;

inline void dfs(int node=0){
    sz[node]=!adj[node].size();
    for(int i:adj[node]){
        dfs(i);
        sz[node]+=sz[i];
        a[node]+=a[i]+sz[i]*c[i];
    }
}

inline int f(int node=0,int b=0){
    if(!adj[node].size())return INT64_MAX;
    int ans=a[node]+b;
    cerr<<"f("<<node<<","<<b<<") = "<<ans<<endl;
    for(int i:adj[node]){
        int ba=b,bsz=n-sz[node],ca=a[node]-a[i],csz=sz[node]-sz[i];
        cerr<<i<<"-"<<node<<" : ba,bsz,ca,czs = "<<ba<<","<<bsz<<","<<ca<<","<<csz<<endl;
        int _=(ba+ca)+(bsz+csz)*3;
        ans=min(ans,f(i,_));
    }
    return ans;
}

signed main(void){
    cin>>n;
    c.resize(n);
    for(int i=0;i<n;i++){
        cin>>s>>x;
        c[i]=s.size()+1;
        adj[i].resize(x);
        cnt+=!x;
        for(int j=0;j<x;j++){
            cin>>adj[i][j];
            adj[i][j]--;
        }
    }

    dfs();
    cout<<f()-cnt<<endl;

    cerr<<"c :";for(int i=0;i<n;i++)cerr<<c [i]<<",";cerr<<endl;
    cerr<<"sz:";for(int i=0;i<n;i++)cerr<<sz[i]<<",";cerr<<endl;
    cerr<<"a :";for(int i=0;i<n;i++)cerr<<a [i]<<",";cerr<<endl;
}

