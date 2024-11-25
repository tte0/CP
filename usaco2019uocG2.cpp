// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=7503;
constexpr int X=2019201913;
constexpr int Y=2019201949;
constexpr int MOD=2019201997;
///////////////////////////////////////////////////////////
int n,k,fa[N];
vector<tuple<signed,signed,signed>> edges;//cost,x,y 
inline int f(int x,int y){
    x++;y++;
    return (X*x+Y*y)%MOD;
}

inline int dsu(int x){
    return fa[x]<0?x:fa[x]=dsu(fa[x]);
}

inline int merge(int x,int y){
    x=dsu(x),y=dsu(y);
    if(x==y)return false;
    fa[x]+=fa[y];
    fa[y]=x;
    return true;
}

signed main(void){
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    memset(fa,-1,sizeof(fa));
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges.push_back({f(i,j),i,j});
        }
    }

    sort(edges.begin(),edges.end());

    int comp=n;
    for(auto [c,x,y]:edges){
        if(comp>k)comp-=merge(x,y);
        else if(merge(x,y)){
            cout<<c<<endl;
            return 0;
        }
    }
}

