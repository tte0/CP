// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int t,n,m,open[N],vis[N];
vector<int> a,b,adj[N];
vector<vector<int>> comp;

inline void solve(void){
    cin>>n>>m;
    a.resize(n);
    b.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int val=n;val>0;val--){
        memset(vis,0,sizeof(vis[0])*(n+5));
        comp.clear();
        for(int i=0;i<n;i++){
            if(a[i]==val)open[i]=1;
        }

        o

        for(int i=0;i<n;i++){
            if(b[i]==val)open[i]=0;
        }
    }
}

signed main(void){
    cin>>t;
    while(t--)solve();
}
