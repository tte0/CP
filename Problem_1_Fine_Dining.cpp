// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=5e4+5;
///////////////////////////////////////////////////////////
int n,m,k,val[N],vis[N][2],ans[N][2];
vector<tuple<int,int>> adj[N];

signed main(void){
    #ifndef LOCAL
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    #endif
    
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        x--;
        val[x]=max(val[x],y);
    }

    priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>> q;//hay,cost,node
    q.push({0,n-1});
    while(q.size()){
        auto [cost,node]=q.top();q.pop();
        if(vis[node][0]++)continue;
        ans[node][0]=cost;

        for(const auto& [i,d]:adj[node]){
            q.push({cost+d,i});
        }
    }

    for(int i=0;i<n;i++){
        if(val[i]){
            q.push({ans[i][0]-val[i],i});
        }
    }
    while(q.size()){
        auto [cost,node]=q.top();q.pop();
        if(vis[node][1]++)continue;
        ans[node][1]=cost;

        for(const auto& [i,d]:adj[node]){
            q.push({cost+d,i});
        }
    }



    for(int i=0;i<n-1;i++){
        cout<<(ans[i][0]>=ans[i][1]?1:0)<<endl;
    }
}
