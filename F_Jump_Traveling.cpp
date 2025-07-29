// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,k;
vector<int> adj[N],bl[N][5],n_adj[N];

inline void solve(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        adj[i].clear();
        n_adj[i].clear();
        for(int j=0;j<=k;j++){
            arr[i][j].clear();
        }
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs();
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
