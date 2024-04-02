/*
MIT License

Copyright (c) 2024 tte0 (teomana,teoata17)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#pragma GCC optimize("-fipa-sra,-fgcse-lm,-fgcse,inline,unroll-all-loops,no-stack-protector,O3,fast-math,Ofast")
#include <bits/stdc++.h>
#define int ll
#define endl '\n'
#define spc ' '
#define pb push_back
#define mset(x,y) memset(x,y,sizeof(x))
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
using namespace std;
typedef int_fast32_t ll;
typedef vector<int> vi;
const int N=200005;
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans,sz[N],depth[N],id[N],di[N],head[N],heavy[N],parent[N],idcnt=0,bl[N][20],st[4*N];
vi v,adj[N];

inline int dfs(int node=0,int p=-1,int d=0){
    parent[node]=p,depth[node]=d,sz[node]=1;

    bl[node][0]=parent[node];
    for(int i=1;i<20;i++)bl[node][i]=bl[bl[node][i-1]][i-1];

    int mxval=-1;
    for(int& i:adj[node]){
        if(i==p)continue;
        int t=dfs(i,node,d+1);
        sz[node]+=t;
        if(t>mxval){
            mxval=t;
            heavy[node]=i;
        }
    }
    return sz[node];
}

inline void dfs2(int node=0){
    id[node]=idcnt;
    di[idcnt++]=node;

    if(node && heavy[parent[node]]==node)head[node]=head[parent[node]];
    else head[node]=node;

    if(heavy[node]!=-1)dfs2(heavy[node]);
    for(int& i:adj[node]){
        if(i==parent[node] || i==heavy[node])continue;
        dfs2(i);
    }
}

inline void debug(){
    cerr<<"sz:      ";for(int i=0;i<n;i++)cerr<<sz[i]<<spc;cerr<<endl;
    cerr<<"depth:   ";for(int i=0;i<n;i++)cerr<<depth[i]<<spc;cerr<<endl;
    cerr<<"id:      ";for(int i=0;i<n;i++)cerr<<id[i]<<spc;cerr<<endl;
    cerr<<"di:      ";for(int i=0;i<n;i++)cerr<<di[i]<<spc;cerr<<endl;
    cerr<<"head:    ";for(int i=0;i<n;i++)cerr<<head[i]<<spc;cerr<<endl;
    cerr<<"heavy:   ";for(int i=0;i<n;i++)cerr<<heavy[i]<<spc;cerr<<endl;
    cerr<<"parent:  ";for(int i=0;i<n;i++)cerr<<parent[i]<<spc;cerr<<endl;
    for(int i=0;i<n;i++){cerr<<"bl: ";for(int j=0;j<20;j++)cerr<<bl[i][j]<<spc;cerr<<endl;}
    cerr<<"st:      ";for(int i=1;i<=4*n;i++)cerr<<st[i]<<spc;cerr<<endl;
    cerr<<endl;
}

/*
inline int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    for(int i=19;i>=0;i--)if(depth[bl[x][i]]>=depth[y])x=bl[x][i];
    if(x==y)return x;
    for(int i=19;i>=0;i--)if(bl[x][i]!=bl[y][i])x=bl[x][i],y=bl[y][i];
    return parent[x];
}
*/

#define mid ((l+r)/2)

inline int stbuild(int l=1,int r=n,int node=1){
    if(l==r)return st[node]=v[di[l-1]];
    return st[node]=stbuild(l,mid,node*2)+stbuild(mid+1,r,node*2+1);
}

inline int stquery(int x,int y,int l=1,int r=n,int node=1){
    //cerr<<"stquery: "<<x<<","<<y<<"|"<<l<<","<<r<<","<<node<<endl;
    if(x>r || y<l)return 0;
    if(x<=l && r<=y)return st[node];
    return stquery(x,y,l,mid,node*2)+stquery(x,y,mid+1,r,node*2+1);
}

inline int stupdate(int pos,int val,int l=1,int r=n,int node=1){
    //cerr<<"stupdate: "<<pos<<","<<val<<"|"<<l<<","<<r<<","<<node<<endl;
    if(r<pos || pos<l)return st[node];
    if(l==r)return st[node]=val;
    return st[node]=stupdate(pos,val,mid+1,r,node*2+1)+stupdate(pos,val,l,mid,node*2);
}

inline void query(int x,int y=0){
    int ans=0;
    while(x!=-1){
        ans+=stquery(id[head[x]]+1,id[x]+1);
        //cerr<<"stquery ok"<<endl;
        x=parent[head[x]];
    }
    cout<<ans<<endl;
}

inline void update(int x,int y){
    stupdate(id[x-1]+1,y);
    //cerr<<"stupdate ok"<<endl;
}

inline void solve(void){
    mset(heavy,-1);
    mset(id,-1);
    mset(head,-1);
    cin>>n>>q;  
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs();
    dfs2();
    stbuild();

    //debug();

    while(q--){
        cin>>x;
        if(x==2){//query between root and x
            cin>>x;x--;
            query(x);
        }
        else{//update x to y
            cin>>x>>y;
            update(x,y);
        }
    }
}

int32_t main(void){
    clock_t start=clock();
    solve();
    while((clock()-start)<=0.585*CLOCKS_PER_SEC);
}
