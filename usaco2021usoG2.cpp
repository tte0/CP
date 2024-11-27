// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
///////////////////////////////////////////////////////////
int n,vis[N][2],comp[N][2],cnt,fa[N];
vector<int> c,v,bt;
vector<vector<int>> p;

inline int dsu(int x){
    return fa[x]<0?x:fa[x]=dsu(fa[x]);
}

inline bool merge(int x,int y){
    x=dsu(x),y=dsu(y);
    if(x==y)return false;
    fa[x]+=fa[y];
    fa[y]=x;
    return true;
}

inline void dfs(int node,int portal){
    int s;
    if(p[node][0]==portal || p[node][1]==portal)s=0;
    else s=2;

    if(vis[node][s>>1]++)return;
    comp[node][s>>1]=cnt;

    dfs(v[p[node][s]]  -node,p[node][s]  );
    dfs(v[p[node][s|1]]-node,p[node][s|1]);
}

signed main(void){
    memset(fa,-1,sizeof(fa));
    cin>>n;
    v.resize(2*n);
    c.resize(n);
    p.resize(n,vector<int>(4));
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<4;j++)cin>>p[i][j];
        for(int j=0;j<4;j++)v[--p[i][j]]+=i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            if(vis[i][j])continue;
            dfs(i,p[i][j<<1]);
            cnt++;
        }
    }

    // cerr<<"vis :";for(int i=0;i<n;i++)cerr<<vis[i][0]<<",";cerr<<endl;
    // cerr<<"vis :";for(int i=0;i<n;i++)cerr<<vis[i][1]<<",";cerr<<endl;
    // cerr<<"comp:";for(int i=0;i<n;i++)cerr<<comp[i][0]<<",";cerr<<endl;
    // cerr<<"comp:";for(int i=0;i<n;i++)cerr<<comp[i][1]<<",";cerr<<endl;

    vector<tuple<int,int,int>> edges;

    for(int i=0;i<n;i++){
        edges.push_back({c[i],comp[i][0],comp[i][1]});
    }

    sort(edges.begin(),edges.end());

    int ans=0;
    for(auto [c,x,y]:edges){
        if(merge(x,y))ans+=c;
    }

    cout<<ans<<endl;
}

