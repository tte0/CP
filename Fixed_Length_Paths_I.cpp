// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,k,ans,sz[N],vis[N],maxd;
vector<int> adj[N];

int compute_sz(int node,int p){
    sz[node]=1;
    for(auto i:adj[node]){
        if(i==p || vis[i])continue;
        sz[node]+=compute_sz(i,node);
    }
}

int centroid(int node,int p,int subtree_size){
    for(auto i:adj[node]){
        if(i==p || vis[i])continue;
        if(sz[i]>/*=*/subtree_size/2)return centroid(i,node,subtree_size);
    }
    return node;
}


void decomp(int node){
    int c=centroid(node,-1,compute_sz(node,-1)/2);
    vis[c]=1;

    for(int i)

    for(auto i:adj[c]){
        decomp(i);
    }
}

signed main(void){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    decomp(0);
}
