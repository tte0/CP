// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=200005;
///////////////////////////////////////////////////////////
int n,m,q,x,y,w,p[N],vis[N],bl[N][20],cost[N][20],depth[N];
vector<tuple<int,int>> adj[N];

inline int query(int x,int y){
    // cerr<<"query:"<<x<<","<<y<<endl;
    if(depth[x]<depth[y])return query(y,x);

    int ans=0;
    while(depth[x]>depth[y]){
        int diff=depth[x]-depth[y];
        ans=max(ans,cost[x][__lg(diff)]);
        x=bl[x][__lg(diff)];
    }

    // cerr<<"q:"<<x<<","<<y<<"|"<<ans<<endl;
    
    if(x==y)return ans;

    for(int i=19;i>=0;i--){
        if(bl[x][i]!=bl[y][i]){
            ans=max(ans,cost[x][i]);
            ans=max(ans,cost[y][i]);
            x=bl[x][i];
            y=bl[y][i];
        }
    }

    return (x!=y)?int(1e18):ans;
}

signed main(void){
    memset(depth,-1,sizeof(depth));
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        x--,y--;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    priority_queue<tuple<int,int,int,int>> pq;//cost,node,parent,depth
    for(int i=0;i<n;i++){
        if(!vis[i])pq.push({0,i,i,0});
        while(pq.size()){
            auto [c,node,b,d]=pq.top();pq.pop();
            if(vis[node]++)continue;
            p[node]=b;
            depth[node]=d;
            for(auto [i,w]:adj[node])pq.push({-w,i,node,d+1});
        }
    }

    for(int node=0;node<n;node++){
        for(auto [i,c]:adj[node]){
            if(node==p[i]){
                cost[i][0]=c;
            }
        }
    }
    for(int i=0;i<n;i++)bl[i][0]=p[i];


    // cerr<<"p:";for(int i=0;i<n;i++)cerr<<p[i]<<",";cerr<<endl;
    // cerr<<"d:";for(int i=0;i<n;i++)cerr<<depth[i]<<",";cerr<<endl;
    // for(int i=0;i<n;i++){
    //     cerr<<"adj:";
    //     for(auto [j,c]:adj[i])cerr<<"["<<j<<"-"<<c<<"],";
    //     cerr<<endl;
    // }
    // for(int j=0;j<3;j++){
    //     cerr<<"bl:";
    //     for(int i=0;i<n;i++)cerr<<bl[i][j]<<",";
    //     cerr<<endl;
    // }
    // for(int j=0;j<3;j++){
    //     cerr<<"cost:";
    //     for(int i=0;i<n;i++)cerr<<cost[i][j]<<",";
    //     cerr<<endl;
    // }


    for(int j=0;j<19;j++){
        for(int i=0;i<n;i++){
            bl[i][j+1]=bl[bl[i][j]][j];
            cost[i][j+1]=max(cost[i][j],cost[bl[i][j]][j]);
        }
    }

    while(q--){
        cin>>x>>y>>w;
        x--,y--;
        int ans=query(y,x);
        // cerr<<"ans:"<<ans<<endl;
        cout<<((ans>w)?"NE":"TAIP")<<endl;
    }
}

