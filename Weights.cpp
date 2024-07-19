#pragma GCC optimize("O3,fast-math,unroll-all-loops")
#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define e2(x) (1LL<<(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define clock() (chrono::high_resolution_clock::now().time_since_epoch().count())
#define compress(x) sort(all(x));x.resize(unique(all(x))-x.begin())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);cout<<fixed<<setprecision(0);cerr<<fixed<<setprecision(0)
using namespace std;
typedef int_fast64_t ll;
typedef string str;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
inline int fp(int b,int p,int mod=1e9+7){
    int ans=1;
    while(p){
        if(p&1)ans=(ans*b)%mod;
        p>>=1;
        b=(b*b)%mod;
    }
    return ans;
}
template<typename T> inline istream& operator>>(istream& is,vector<T>& a) {
    for(T& _:a)is>>_;
    return is;
}
inline void print(){cout<<endl;}
template<typename... Args> inline void print(const Args&... args){
    ((cout<<args<<' '),...)<<endl;
}
inline void input(){}
template<typename... Args> inline void input(Args&... args){
    (cin>>...>>args);
}
#ifdef ONLINE_JUDGE
template<typename... Args> inline void debug(const Args&... args){
    return void("59");
}
#else
inline void debug(){cerr<<endl;}
template<typename... Args> inline void debug(const Args&... args){
    ((cerr<<args<<' '),...)<<endl;
}
#endif
const int N=2e5+5;
const int MOD=998244353;
int n,m,k,t,q,a,b,x,y,w,ans,parent[2*N],lchild[N],rchild[N],depth[N],sdepth[N];
ii st[2*N];
vi v,bt,tb;
vii range;
str s;

inline int preorder(int node=0,int d=0,int lr=0){
    if(node>=n){
        bt.pb(node-n);
        depth[node-n]=d;
        return node-n;
    }
    sdepth[node]=d;
    int l=preorder(lchild[node],d+1,0);
    int r=preorder(rchild[node],d+1,1);
    range[node]={l,r};
    if(lr==0)return l;
    else     return r;
}

inline ii _max(ii a,ii b){
    if(a.ff<b.ff)swap(a,b);
    ii _a=a,_b=b;
    a.ff-=b.ff;b.ff=0;
    if(a.ff>=30 || e2(a.ff)*a.ss>b.ss)return _a;
    else return _b;
}

#define mid ((l+r)/2)
inline ii build(int l=0,int r=n,int node=1){
    if(l==r)return st[node]={depth[tb[l]],v[tb[l]]};
    return st[node]=_max(build(l,mid,node*2),build(mid+1,r,node*2+1));
}

inline ii query(int l=0,int r=n,int node=1){
    if(x<=l && r<=y)return st[node];
    if(r<x || y<l)return {0,0};
    return _max(query(l,mid,node*2),query(mid+1,r,node*2+1));
}

inline ii update(int l=0,int r=n,int node=1){
    if(r<x || x<l)return st[node];
    if(l==r){
        st[node].ss=y;
        return st[node];
    }
    return st[node]=_max(update(l,mid,node*2),update(mid+1,r,node*2+1));
}
#undef mid

inline void solve(void){
    mset(parent,-1);mset(lchild,-1);mset(rchild,-1);
    input(n,q);
    v.resize(n+1);
    range.resize(n);
    for(int i=0;i<n;i++){
        input(s,x);x--;
        if(s=="S")lchild[i]=x,parent[x]=i;
        else lchild[i]=x+n,parent[x+n]=i;

        input(s,x);x--;
        if(s=="S")rchild[i]=x,parent[x]=i;
        else rchild[i]=x+n,parent[x+n]=i;
    }
    input(v);
    
    preorder();
    tb.resize(n+1);for(int i=0;i<=n;i++)tb[bt[i]]=i;
    //debug("bt:",bt);
    //debug("tb:",tb);
    //debug("range:",range);
    //cerr<<"depth: ";for(int i=0;i<=n;i++)cerr<<depth[i]<<" ";cerr<<endl;
    build();
    //for(int i=0;i<=2*n;i++)cerr<<"st: "<<st[i]<<endl;

    while(q--){
        input(x);
        if(x==1){//update
            input(x,y);
            x--;
            x=tb[x];
            update();
        }
        else{//query
            input(w);
            w--;
            x=bt[range[w].ff],y=bt[range[w].ss];
            //debug("query range:",x,y);
            ii ans=query();
            ans.ff-=sdepth[w],
            print((fp(2,ans.ff,MOD)*ans.ss)%MOD);
        }
    }
}

signed main(void){
    fastio;
    solve();
}
