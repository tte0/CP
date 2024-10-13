// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
constexpr int INF=1e9+7;
int n,x,y,w,m,q,adj[303][303];
vector<pair<int,int>> query;
vector<pair<int,pair<int,int>>> edges;

signed main(void){
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=INF;
    
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;x--,y--;
        edges.push_back({w,{x,y}});
    }

    for(int i=0;i<q;i++){
        cin>>x;
        if(x==1){
            cin>>x;x--;
            query.push_back({x,-1});
        }
        else{
            cin>>x>>y;x--,y--;
            query.push_back({x,y});
        }
    }
}
