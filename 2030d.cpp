// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=200005;
///////////////////////////////////////////////////////////
int n,q,x,y,w,st[4*N],lazy[4*N];
string s;
vector<int> p,_p,v;

#define mid ((l+r)>>1)

inline int build(int l=1,int r=n,int node=1){
    if(l==r)return st[node]=v[l-1];
    return st[node]=min(build(l,mid,node<<1),build(mid+1,r,node<<1|1));
}

inline void push(int l,int r,int node){
    st[node]+=lazy[node];
    if(l<r){
        lazy[node<<1]+=lazy[node];
        lazy[node<<1|1]+=lazy[node];
    }
    lazy[node]=0;
}

inline int update(int l=1,int r=n,int node=1){
    push(l,r,node);
    if(r<x)return st[node];
    if(x<=l){
        lazy[node]+=w;
        push(l,r,node);
        return st[node];
    }
    return st[node]=min(update(l,mid,node<<1),update(mid+1,r,node<<1|1));
}

inline void solve(){
    cin>>n>>q;
    p.resize(n);
    _p.resize(n);
    v.resize(n);
    for(int i=0;i<=4*n;i++)st[i]=lazy[i]=0;
    for(int i=0;i<n;i++){
        cin>>x;x--;
        p[i]=x;
        _p[x]=i;
    }
    cin>>s;
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(s[i]=='R');
        v[i]=sum;
    }
    sum=0;
    for(int i=0;i<n;i++){
       sum-=(s[_p[i]]=='R');
       v[i]+=sum;
    }

    build();

    cerr<<"p:";for(int i:p)cerr<<i<<",";cerr<<endl;
    cerr<<"_p:";for(int i:_p)cerr<<i<<",";cerr<<endl;
    cerr<<"v:";for(int i:v)cerr<<i<<",";cerr<<endl;
    cerr<<"st:";for(int i=1;i<4*n;i++)cerr<<st[i]<<",";cerr<<endl;
    cerr<<"lz:";for(int i=1;i<4*n;i++)cerr<<lazy[i]<<",";cerr<<endl;
    cerr<<endl;

    while(q--){
        cin>>x;
        w=s[x-1]=='R'?-1:1;
        s[x-1]=('L'+'R')-s[x-1];
        cerr<<"update ["<<x<<",n) "<<(w<0?'-':'+')<<abs(w)<<endl;
        update();
        cerr<<"st:";for(int i=1;i<4*n;i++)cerr<<st[i]<<",";cerr<<endl;
        cerr<<"lz:";for(int i=1;i<4*n;i++)cerr<<lazy[i]<<",";cerr<<endl;
        x=_p[x-1]+1;
        w-=w<<1;
        cerr<<"update ["<<x<<",n) "<<(w<0?'-':'+')<<abs(w)<<endl;
        update();
        cout<<(0<=st[1]?"YES":"NO")<<endl;

        cerr<<"st:";for(int i=1;i<4*n;i++)cerr<<st[i]<<",";cerr<<endl;
        cerr<<"lz:";for(int i=1;i<4*n;i++)cerr<<lazy[i]<<",";cerr<<endl;
        cerr<<endl;
    }
    cout<<endl;
    cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}

