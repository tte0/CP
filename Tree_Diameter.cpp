#pragma GCC optimize("-fipa-sra,-fgcse-lm,-fgcse,inline,unroll-all-loops,no-stack-protector,O3,fast-math,Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define N (200005)
#define INF (int(4e18))
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
/////////////////////////////////////////////////////////////
int n,x,y,maxd=-INF,maxnode=-INF;
vi adj[N];

inline void dfs(int node,int p,int depth){
    if(maxd<depth){
        maxd=depth;
        maxnode=node;
    }
    for(int i:adj[node]){
        if(i!=p){
            dfs(i,node,depth+1);
        }
    }
    return; 
}

int32_t main(void){
    fastio;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,0);
    dfs(maxnode,0,0);
    cout<<maxd<<endl;
    return 0;
}
