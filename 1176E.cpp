// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m;
vector<int> adj[N];

inline void solve(void){
    cin>>n>>m;
    for(int i=0;i<n;i++)adj[i].clear();
    for(int i=0;i<m;i++){
        static int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    
    vector<int> a,b,vis(n,0);
    queue<tuple<int,int>> q;q.push({0,0});
    while(q.size()){
        auto [node,x]=q.front();q.pop();
        if(vis[node]++)continue;
        if(x)a.push_back(node+1);
        else b.push_back(node+1);
        for(auto i:adj[node])q.push({i,x^1});
    }

    if(a.size()>b.size())swap(a,b);

    cout<<a.size()<<endl;
    for(auto i:a)cout<<i<<" ";
    cout<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
