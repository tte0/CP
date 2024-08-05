#pragma GCC optimize("inline,unroll-all-loops,no-stack-protector,Ofast")
#include <bits/stdc++.h>
#define int ll
#define endl '\n'
#define spc ' '
#define pb push_back
#define mset(x,y) memset(x,y,sizeof(x))
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fileio freopen("correct_output.txt","w",stdout);freopen("testcase.in","r",stdin)
using namespace std;
typedef int_fast32_t ll;
typedef vector<int> vi;
const int N=200005;
///////////////////////////////////////////////////////////////////
int n,q,x,y,sz[N],depth[N],id[N],di[N],head[N],heavy[N],parent[N],idcnt=0,st[2*N],v[N];
vi adj[N];
 
inline int dfs(int node=0,int p=-1,int d=0){
    parent[node]=p,depth[node]=d,sz[node]=1;

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
 
#define mid ((l+r)/2)
 
inline void stbuild(){
    for(int i=0;i<n;i++)st[i+n]=v[di[i]];
    for(int i=n-1;i>0;i--)st[i]=max(st[i*2],st[i*2+1]);

    //if(l==r)return st[node]=v[di[l-1]];
    //return st[node]=max(stbuild(l,mid,node*2),stbuild(mid+1,r,node*2+1));
}
 
inline int stquery(int x,int y){
    //cerr<<"stquery: "<<x<<","<<y<<"|"<<l<<","<<r<<","<<node<<endl;
    if(x>y)swap(x,y);
    x--;
    int ans=0;
    for(x+=n,y+=n;x<y;x>>=1,y>>=1){
        if(x&1)ans=max(ans,st[x++]);
        if(y&1)ans=max(ans,st[--y]);
    }
    return ans;
    //if(x>r || y<l)return 0;
    //if(x<=l && r<=y)return st[node];
    //return max(stquery(x,y,l,mid,node*2),stquery(x,y,mid+1,r,node*2+1));
}
 
inline void stupdate(int pos,int val){
    //cerr<<"stupdate: "<<pos<<","<<val<<"|"<<l<<","<<r<<","<<node<<endl;
    for(st[pos+=n]=val;pos>1;pos>>=1)st[pos>>1]=max(st[pos],st[pos^1]);
    
    //if(r<pos || pos<l)return st[node];
    //if(l==r)return st[node]=val;
    //return st[node]=max(stupdate(pos,val,mid+1,r,node*2+1),stupdate(pos,val,l,mid,node*2));
}
 
inline int query(int x,int y){
    int ans=0;
    while(head[x]!=head[y]){
        if(depth[head[x]]<depth[head[y]])swap(x,y);
        ans=max(ans,stquery(id[head[x]]+1,id[x]+1));
        //cerr<<"stquery ok"<<endl;
        x=parent[head[x]];
    }
    ans=max(ans,stquery(id[x]+1,id[y]+1));
    return ans;
}
 
inline void update(int x,int y){
    stupdate(id[x-1],y);
    //cerr<<"stupdate ok"<<endl;
}
 
inline void debug(){
    /*cerr<<"sz:      ";for(int i=0;i<n;i++)cerr<<sz[i]<<spc;cerr<<endl;
    cerr<<"depth:   ";for(int i=0;i<n;i++)cerr<<depth[i]<<spc;cerr<<endl;
    cerr<<"id:      ";for(int i=0;i<n;i++)cerr<<id[i]<<spc;cerr<<endl;
    cerr<<"di:      ";for(int i=0;i<n;i++)cerr<<di[i]<<spc;cerr<<endl;
    cerr<<"head:    ";for(int i=0;i<n;i++)cerr<<head[i]<<spc;cerr<<endl;
    cerr<<"heavy:   ";for(int i=0;i<n;i++)cerr<<heavy[i]<<spc;cerr<<endl;
    cerr<<"parent:  ";for(int i=0;i<n;i++)cerr<<parent[i]<<spc;cerr<<endl;*/
    cerr<<"st:      ";for(int i=1;i<2*n;i++)cerr<<st[i]<<spc;
    cerr<<endl;
}

inline void solve(void){
    mset(heavy,-1);
    mset(id,-1);
    mset(head,-1);
    cin>>n>>q;  
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=1;i<n;i++){
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs();
    dfs2();
    //debug();
    stbuild();
 
    //debug();
 
    while(q--){
        cin>>x;
        if(x==2){//query between x and y
            cin>>x>>y;x--;y--;
            cout<<query(x,y)<<spc;
        }
        else{//update x to y
            cin>>x>>y;
            update(x,y);
        }
        //debug();
    }
}
 
int32_t main(void){
    fileio;
    clock_t start=clock();
    solve();
    //cerr<<"Execution Time: "<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
    cout.flush();
}