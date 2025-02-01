// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n;
vector<int> adj[N];

inline void solve(void){
    cin>>n;
    for(int i=0;i<n;i++)adj[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
}

signed main(void){
    int t;
    cin>>t;    
    while(t--)solve();
}
