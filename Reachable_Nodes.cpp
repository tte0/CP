// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native,popcnt")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=50000;
///////////////////////////////////////////////////////////
int n,m,x,y;
bitset<N> bt[N];
vector<int> adj[N];

inline void dfs(int node=0){
    if(bt[node][node])return;
    bt[node][node]=1;
    for(auto i:adj[node]){
        dfs(i);
        bt[node]|=bt[i];
    }
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
    }

    for(int i=0;i<n;i++){
        dfs(i);
    }

    for(int i=0;i<n;i++)cout<<bt[i].count()<<" ";
}
