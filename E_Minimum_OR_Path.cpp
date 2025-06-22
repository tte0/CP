// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
inline constexpr auto bit=[](int x,int b){return x&(1LL<<b);};
///////////////////////////////////////////////////////////
int n,m,vis[N];
vector<tuple<int,int>> adj[N];

inline bool check(int b){
    static int vis[N];
    priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>> q;
    memset(vis,-1,sizeof(vis));
    q.push({0,0});
    while(q.size()){
        auto [d,node]=q.top();q.pop();
        if(vis[node]!=-1)continue;
        vis[node]=d;
        for(auto [i,w]:adj[node])q.push({d|bit(w,b),i});
    }
    return vis[n-1];
}

inline void remove(int b){
    for(int node=0;node<n;node++){
        vector<tuple<int,int>> temp;
        temp.reserve(adj[node].size());
        for(auto [i,w]:adj[node]){
            if(!bit(w,b))temp.push_back({i,w});
        }
        swap(temp,adj[node]);
    }
}

signed main(void){
    memset(vis,-1,sizeof(vis));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        static int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    int ans=0;
    for(int b=32;b--;){
        if(check(b))ans|=1LL<<b;
        else remove(b);
    }

    cout<<ans<<endl;
}
