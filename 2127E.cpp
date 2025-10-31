// Author: Teoman Ata Korkmaz
#pragma GCC optimize ("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,k;
vector<int> w,c,adj[N];
map<int,int> mp[N];

int dfs(int node=0,int p=-1){
    int cost=0,x=-1;
    for(const auto& i:adj[node]){
        cost+=dfs(i,node);
        if(mp[node].size()<mp[i].size())swap(mp[node],mp[i]);

        for(const auto& [key,value]:mp[i]){
            if(mp[node][key]){
                if(x==-1)
            }
        }
    }
}

inline void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)adj[i].clear();
    for(int i=0;i<n;i++)mp[i].clear();
    w.resize(n);
    c.resize(n);
    for(auto& i:w)cin>>i;
    for(auto& i:c)cin>>i;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    cout<<dfs()<<endl;
    for(const auto& i:c)cout<<i<<" ";
    cout<<endl;
}

signed main(void){
   int t;
   cin>>t;
   while(t--)solve(); 
}
