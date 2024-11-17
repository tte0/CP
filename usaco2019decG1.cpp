// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1003;
constexpr int INF=1e18+18;
///////////////////////////////////////////////////////////
int n,m,x,y,f,c,vis[N][N];
vector<tuple<int,int,int>> adj[N];

signed main(void){
    freopen("pump.in","r",stdin);
    freopen("pump.out","w",stdout);
    memset(vis,-1,sizeof(vis));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>c>>f;
        x--,y--;
        adj[x].push_back({y,c,f});
        adj[y].push_back({x,c,f});
    }

    priority_queue<tuple<int,int,int>> q;//-cost,node,flow
    q.push({0,0,N-1});
    while(q.size()){
        auto [c,node,f]=q.top();q.pop();
        if(vis[node][f]!=-1)continue;
        vis[node][f]=-c;

        for(auto [i,ci,fi]:adj[node]){
            q.push({c-ci,i,min(f,fi)});
        }
    }

    int ans=0;
    for(int i=0;i<N;i++){
        ans=max(ans,(i*1000000)/vis[n-1][i]);
    }
    cout<<ans<<endl;
}

