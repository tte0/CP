// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e5+5;
///////////////////////////////////////////////////////////
int n;
vector<int> adj[N],c_adj[N];

inline void build(int node,int p,int head){
    if(adj[node].size()==2)return build(adj[node][0]+adj[node][1]-p,node,head);
    c_adj[node].push_back(head);
    c_adj[head].push_back(node);
    for(auto i:adj[node]){
        if(i==p)continue;
        build(i,node,node);
    }
}

inline void solve(void){
    cin>>n;
    for(int i=0;i<n;i++)adj[i].clear(),c_adj[i].clear();
    for(int i=1;i<n;i++){
        static int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0;i<n;i++){
        if(adj[i].size()==1){
            build(i,-1,i);
            assert(c_adj[i].size()>=2 && c_adj[i][0]==i && c_adj[i][0]==i);
            c_adj[i].erase(c_adj[i].begin(),c_adj[i].begin()+2);
            break;
        }
    }

    /*for(int i=0;i<n;i++){
        cerr<<i+1<<":";
        for(int j:c_adj[i])cerr<<j+1<<",";
        cerr<<endl;
    }*/
    
    
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
