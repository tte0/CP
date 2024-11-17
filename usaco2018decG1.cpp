// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1003;
///////////////////////////////////////////////////////////
int n,ans,fa[N];
vector<tuple<int,int>> v;

inline int dsu(int x){
    return (fa[x]<0)?(x):(fa[x]=dsu(fa[x]));
}

inline bool merge(int x,int y){
    x=dsu(x),y=dsu(y);
    // cerr<<"merge:"<<x<<","<<y<<endl;
    if(x==y)return false;
    fa[x]+=fa[y];
    fa[y]=x;
    return true;
}

inline int dist(tuple<int,int> a,tuple<int,int> b){
    auto [xa,ya]=a;
    auto [xb,yb]=b;
    return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}

signed main(void){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    memset(fa,-1,sizeof(fa));
    cin>>n;
    v.resize(n);
    for(auto& [x,y]:v)cin>>x>>y;

    priority_queue<tuple<int,int,int>> q;//-cost,i,j
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            q.push({-dist(v[i],v[j]),i,j});
        }
    }

    while(q.size()){
        auto [c,x,y]=q.top();q.pop();
        // cerr<<"c,x,y:"<<c<<","<<x<<","<<y<<endl;
        if(merge(x,y))ans=min(ans,c);
    }

    cout<<-ans<<endl;
}

