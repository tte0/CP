// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
///////////////////////////////////////////////////////////
int n,fa[N];
vector<tuple<int,int>> v;
vector<tuple<int,int,int>> edges;

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

inline int dist(tuple<int,int> i,tuple<int,int> j){
    auto [x,y]=i;
    auto [a,b]=j;
    return (x-a)*(x-a)+(y-b)*(y-b);
}

signed main(void){
    memset(fa,-1,sizeof(fa));
    cin>>n;
    v.resize(n);
    for(auto& [x,y]:v)cin>>x>>y;

    sort(v.begin(),v.end());

    vector<int> mx(11,-1);
    for(int i=0;i<n;i++){
        auto [x,y]=v[i];
        // cerr<<"x,y:"<<x<<","<<y<<endl;
        for(int j=0;j<=10;j++){
            // cerr<<"i,j,mx:"<<i<<","<<j<<","<<mx[j]<<endl;
            if(mx[j]!=-1){
                edges.push_back({dist(v[i],v[mx[j]]),i,mx[j]});
            }
        }
        mx[y]=i;
    }

    sort(edges.begin(),edges.end());

    int ans=0;
    for(auto [c,x,y]:edges){
        // cerr<<"c,x,y:"<<c<<","<<x<<","<<y<<endl;
        if(merge(x,y))ans+=c;
    }

    cout<<ans<<endl;
}

