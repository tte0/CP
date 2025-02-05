// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m,q,x,y,w,bl[N][18],cost[N][18],depth[N],order[N],ordercnt,cnt[N];
vector<int> v;
vector<tuple<int,int>> adj[N],virt[N];
vector<tuple<int,int,int>> edges;
priority_queue<tuple<int,int>> pq;

inline void dfs(int node=0,int p=0,int d=0){
    order[node]=ordercnt++;
    bl[node][0]=p;
    depth[node]=d;
    for(auto [i,w]:adj[node]){
        if(i==p)continue;
        cost[i][0]=w;
        dfs(i,node,d+1);
    }
}
inline void build(){
    for(int j=0;j<17;j++){
        for(int i=0;i<n;i++){
            bl[i][j+1]=bl[bl[i][j]][j];
            cost[i][j+1]=cost[i][j]+cost[bl[i][j]][j];
        }
    }
}
inline int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    for(int i=17;i>=0;i--){
        if(depth[x]-(1<<i)>=depth[y])x=bl[x][i];
    }

    if(x==y)return x;

    for(int i=17;i>=0;i--){
        if(bl[x][i]!=bl[y][i]){
            x=bl[x][i];
            y=bl[y][i];
        }
    }
    assert(bl[x][0]==bl[y][0]);
    return bl[x][0];
}
inline void addedge(int x,int y){
    if(depth[x]<depth[y])swap(x,y);

    int w=0,_x=x;
    for(int i=17;i>=0;i--){
        if(depth[x]-(1<<i)>=depth[y]){
            w+=cost[x][i];
            x=bl[x][i];
        }
    }
    x=_x;

    virt[x].push_back({y,w});
    virt[y].push_back({x,w});
    edges.push_back({x,y,w});
}
inline void virtualtree(){
    sort(v.begin(),v.end(),[&](int a,int b){return order[a]<order[b];});
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;
    edges.clear();
    while(pq.size())pq.pop();
    for(auto i:v)virt[i].clear(),cnt[i]=1,pq.push({depth[i],i});

    for(int i=0;i<m-1;i++){
        int x=v[i],y=v[i+1],l=lca(x,y);
        if(x==l || y==l){
            addedge(x,y);
            //cerr<<"nein"<<endl;
        }
        else{
            virt[l].clear(),cnt[l]=0;
            addedge(x,l);
            addedge(y,l);
            //cerr<<"ya"<<endl;
        }
    }

}
inline void debug(){
    for(int i=0;i<n;i++){
        cerr<<"virt["<<i<<"]:";
        for(auto [y,w]:virt[i])cerr<<"["<<y<<","<<w<<"], ";
        cerr<<endl;
    }
    for(auto [x,y,w]:edges)cerr<<"edges: ["<<x<<","<<y<<","<<w<<"]\n";

    auto _pq=pq;
    cerr<<"pq: ";
    while(_pq.size()){
        auto [a,b]=_pq.top();_pq.pop();
        cerr<<"["<<a<<","<<b<<"], ";
    }
    cerr<<"\n";
}
inline void solve(){
    debug();
    int ans=0;
    while(pq.size()){
        auto [d,node]=pq.top();pq.pop();
        cerr<<"node,d:"<<node<<","<<d<<endl;
        cerr<<"cnt:"<<cnt[node]<<endl;
        cnt[node]%=2;
        if(cnt[node]==0)continue;

        int p=-1,c=-1;
        for(auto [i,w]:virt[node]){
            if(depth[i]<depth[node]){
                p=i;
                c=w;
                break;
            }
        }
        cerr<<"p,c:"<<p<<","<<c<<endl;
        assert(p!=-1);
        ans+=c;
        cnt[p]++;
        pq.push({depth[p],p});
        cnt[node]=0;
    }

    cout<<ans<<endl;
    cerr<<endl;
}

signed main(void){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    dfs();
    build();

    while(q--){
        cin>>m;
        v.resize(m);
        for(auto& i:v)cin>>i;

        virtualtree();
        solve();
    }
}
