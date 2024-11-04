// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
constexpr int INF=1e18+7;
int n,x,y,w,m,q,adj[303][303],erased[100005];
vector<int> ans;
vector<tuple<int,int>> query;
vector<tuple<int,int,int>> edges;

inline void add(int ind){
    auto [x,y,w]=edges[ind];
    if(adj[x][y]<=w)return;

    adj[x][y]=adj[y][x]=w;
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            adj[a][b]=min(adj[a][b],adj[a][x]+w+adj[y][b]);
            adj[a][b]=min(adj[a][b],adj[a][y]+w+adj[x][b]);
        }
    }
}

signed main(void){
    cin>>n>>m>>q;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=INF;
    for(int i=0;i<n;i++)adj[i][i]=0;
    
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;x--,y--;
        edges.push_back({x,y,w});
    }

    for(int i=0;i<q;i++){
        cin>>x;
        if(x==1){
            cin>>x;x--;
            query.push_back({x,-1});
            erased[x]=1;
        }
        else{
            cin>>x>>y;x--,y--;
            query.push_back({x,y});
        }
    }

    for(int i=0;i<m;i++){
        if(erased[i])continue;
        auto [x,y,w]=edges[i];
        adj[x][y]=adj[y][x]=w;
    }
    for(int k=0;k<n;k++){
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                adj[a][b]=min(adj[a][b],adj[a][k]+adj[k][b]);
            }
        }
    }

    reverse(query.begin(),query.end());

    for(auto [x,y]:query){
        if(y==-1){
            add(x);
        }
        else{
            ans.push_back(adj[x][y]);
        }
    }

    reverse(ans.begin(),ans.end());

    for(auto i:ans)cout<<(1e15<=i?-1:i)<<endl;
}
