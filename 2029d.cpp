// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
///////////////////////////////////////////////////////////
int n,m,x,y;
vector<int> adj[N];
vector<tuple<int,int,int>> ans;

inline void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++)adj[i].clear();
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}

