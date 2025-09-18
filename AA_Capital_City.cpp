// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m,last[N],depth[N],parent[N],sz[N],heavy[N],head[N],id[N],di[N],cnt,vis[2*N],which[2*N];
vector<int> v,adj[N],n_adj[2*N],r_n_adj[2*N],crazy[N],bt;
vector<pair<int,int>> query;
vector<vector<int>> scc;

void dfs(int node=0,int p=0,int d=0){
    parent[node]=p;
    depth[node]=d;
    sz[node]=1;
    //cerr<<"dfs:"<<node<<","<<p<<endl;
    if(last[v[node]]!=-1)query.push_back({last[v[node]],node});
    last[v[node]]=node;
    for(const int& i:adj[node]){
        if(i==p)continue;
        dfs(i,node,d+1);
        sz[node]+=sz[i];
        if(!heavy[node] || sz[heavy[node]]<sz[i])heavy[node]=i;
    }
}
void dfs2(int node=0,int h=0){
    id[node]=cnt;
    di[cnt++]=node;
    head[node]=h;
    if(heavy[node])dfs2(heavy[node],h);
    else{
        int _n=(id[node]-id[head[node]]+1);
        crazy[h].resize(2*_n);
        for(int i=1;i<_n;i++)crazy[h][i]=n+id[head[node]]+i-1;
        for(int i=_n;i<2*_n;i++)crazy[h][i]=v[di[i-_n+id[head[node]]]];

        for(int i=1;i<_n;i++){
            n_adj[crazy[h][i]].push_back(crazy[h][i<<1]);
            n_adj[crazy[h][i]].push_back(crazy[h][(i<<1)|1]);
        }
    }
    for(const int& i:adj[node]){
        if(i==parent[node] || i==heavy[node])continue;
        dfs2(i,i);
    }
}
void debug(){
    cerr<<"parent:";for(int i=0;i<n;i++)cerr<<parent[i]+1<<",";cerr<<endl;
    cerr<<"depth:";for(int i=0;i<n;i++)cerr<<depth[i]<<",";cerr<<endl;
    cerr<<"sz:";for(int i=0;i<n;i++)cerr<<sz[i]<<",";cerr<<endl;
    cerr<<"heavy:";for(int i=0;i<n;i++)cerr<<heavy[i]+1<<",";cerr<<endl;
    cerr<<"head:";for(int i=0;i<n;i++)cerr<<head[i]+1<<",";cerr<<endl;
    cerr<<"id:";for(int i=0;i<n;i++)cerr<<id[i]+1<<",";cerr<<endl;
    cerr<<endl;
    for(int i=0;i<n;i++){
        cerr<<"crazy:";for(const int& j:crazy[i])cerr<<j+1<<",";cerr<<endl;
    }
    cerr<<"query:";for(auto [a,b]:query)cerr<<"["<<a+1<<","<<b+1<<"] ";cerr<<endl;
    cerr<<"----------------------------------------"<<endl;
}
void st_query(int l,int r,int h,int val){
    //cerr<<"stquery:"<<l+1<<","<<r+1<<","<<h+1<<","<<val+1<<endl;
    int n=crazy[h].size()/2;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)n_adj[val].push_back(crazy[h][l++]);
        if(r&1)n_adj[val].push_back(crazy[h][--r]);
    }
}
void hld_query(int a,int b,int val){
    //cerr<<"hld:"<<a+1<<","<<b+1<<","<<val+1<<endl;
    while(head[a]!=head[b]){
        if(depth[head[a]]<depth[head[b]])swap(a,b);
        //cerr<<"a,b:"<<a+1<<","<<b+1<<endl;
        st_query(0,id[a]-id[head[a]]+1,head[a],val);
        a=parent[head[a]];
    }
    if(depth[a]<depth[b])swap(a,b);
    assert(head[a]==head[b]);
    st_query(id[b]-id[head[a]],id[a]-id[head[a]]+1,head[a],val);
}
void dfs3(int node){
    //cerr<<"dfs3:"<<node<<endl;
    if(vis[node]++)return;
    for(const int& i:n_adj[node]){
        dfs3(i);
    }
    bt.push_back(node);
}
void dfs4(int node){
    //cerr<<"dfs4:"<<node<<endl;
    if(vis[node]++)return;
    scc.back().push_back(node);
    which[node]=scc.size()-1;
    for(const int& i:r_n_adj[node]){
        dfs4(i);
    }
}
void debug2(){
    for(int i=0;i<2*n;i++){
        cerr<<"n_adj["<<i+1<<"]:";for(const int& j:n_adj[i])cerr<<j+1<<",";cerr<<endl;
    }
    for(int i=0;i<2*n;i++){
        cerr<<"r_n_adj["<<i+1<<"]:";for(const int& j:r_n_adj[i])cerr<<j+1<<",";cerr<<endl;
    }
    cerr<<"bt:";for(int i=0;i<2*n;i++)cerr<<bt[i]+1<<",";cerr<<endl;
    for(int i=0;i<scc.size();i++){
        cerr<<"scc["<<i+1<<"]:";for(const int& j:scc[i])cerr<<j+1<<",";cerr<<endl;
    }
    cerr<<"which:";for(int i=0;i<2*n;i++)cerr<<which[i]+1<<",";cerr<<endl;
}
signed main(void){
    memset(last,-1,sizeof(last));
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);mp
    }
    v.resize(n);
    for(auto& i:v){cin>>i;i--;}

    dfs();
    dfs2();

    //debug();
    for(int i=0;i<query.size();i++){
        auto [x,y]=query[i];
        assert(v[x]==v[y]);
        //cerr<<"query:"<<x+1<<","<<y+1<<endl;
        hld_query(x,y,v[x]);
    }

    for(int i=0;i<2*n;i++){
        n_adj[i].shrink_to_fit();
        for(const int& j:n_adj[i])r_n_adj[j].push_back(i);
    }

    for(int i=0;i<2*n;i++){
        dfs3(i);
    }
    reverse(bt.begin(),bt.end());
    memset(vis,0,sizeof(vis));
    for(const int& node:bt){
        if(vis[node])continue;
        scc.push_back({});
        dfs4(node);
    }

    //debug2();

    for(int i=0;i<scc.size();i++){
        for(const int& j:n_adj[i]){
            if(which[i]!=which[j])scc[which[i]].clear();
        }
    }

    /*for(int i=0;i<scc.size();i++){
        cerr<<"scc["<<i+1<<"]:";for(const int& j:scc[i])cerr<<j+1<<",";cerr<<endl;
    }*/

    int ans=12341234;
    for(int i=0;i<scc.size();i++){
        if(scc[i].empty())continue;
        int cnt=-1;
        for(const int& j:scc[i])cnt+=(j<m);
        if(cnt!=-1)ans=min(ans,cnt);
    }

    cout<<ans<<endl;
}
