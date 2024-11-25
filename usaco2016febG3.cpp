// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
// #define int int_fast64_t
using namespace std;
constexpr int N=4400006;
///////////////////////////////////////////////////////////
int A,B,n,m,fa[N];
vector<int> a,b;
vector<tuple<int,int,int>> edges;// cost,x,y

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

signed main(void){
    // freopen("fencedin.in", "r", stdin);
    // freopen("fencedin.out", "w", stdout);
    memset(fa,-1,sizeof(fa));
    cin>>A>>B>>n>>m;
    a.resize(n);
    b.resize(m);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    for(int i=0;i<1000000000;i++);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    a.insert(a.begin(),0);a.push_back(A);
    b.insert(b.begin(),0);b.push_back(B);

    // for(int i=n-1;i>0;i--)a[i]-=a[i-1];
    // for(int i=m-1;i>0;i--)b[i]-=b[i-1];

    // cerr<<"a:";for(auto i:a)cerr<<i<<",";cerr<<endl;
    // cerr<<"b:";for(auto i:b)cerr<<i<<",";cerr<<endl;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j<m)edges.push_back({a[i+1]-a[i],i+j*(n+1),i+(j+1)*(n+1)});
            if(i<n)edges.push_back({b[j+1]-b[j],i+j*(n+1),(i+1)+j*(n+1)});
        }
    }

    sort(edges.begin(),edges.end());

    long long ans=0;
    for(auto [c,x,y]:edges){

        if(merge(x,y)){
            ans+=c;
            // cerr<<"++";
        }
        // cerr<<endl;
        
    }
    cout<<ans<<endl;
}

