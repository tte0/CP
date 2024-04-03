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
#pragma GCC optimize("O3,fast-math")
#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define e2(x) (1LL<<(x))
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define smrt(i) (double(sqrt(8*(i)+1)-1)/2)
#define ssum(x) ((x)*((x)+1)/2)
#define isint(x) (ceil((x))==floor((x)))
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define cendl cout<<endl
#define mset(x,y) memset(x,y,sizeof(x))
#define popcnt(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
#define fileio freopen("out.put","w",stdout);freopen("in.put","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
#define wait while(clock()-start<=0.585*CLOCKS_PER_SEC);
using namespace std;
typedef int_fast64_t ll;
typedef long double ldouble;
typedef string str;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pair<char,int>> vci;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
const int N=100005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans,depth[N],sz[N],parent[N],heavy[N],head[N],id[N],st[2*N],idcnt;
vi v,adj[N];

inline int dfs(int node=0,int p=-1,int d=0){
    sz[node]=1;
    parent[node]=p;
    depth[node]=d;
    int mx=0;
    for(int& i:adj[node]){
        if(i==parent[node])continue;
        int t=dfs(i,node,d+1);
        sz[node]+=t;
        if(t>mx){
            heavy[node]=i;
            mx=t;
        }
    }
    return sz[node];
}

inline void dfs2(int node=0){
    //cerr<<"dfs2: "<<1+node<<endl;
    if(node && heavy[parent[node]]==node)head[node]=head[parent[node]];
    else head[node]=node;
    
    id[node]=idcnt++;

    if(heavy[node]!=-1)dfs2(heavy[node]);
    for(int& i:adj[node]){
        if(i==parent[node] || i==heavy[node])continue;
        dfs2(i);
    }
}

inline void stbuild(){
    for(int i=1;i<2*n;i++)st[i]=INF;
}

inline int stquery(int l,int r){
    int ans=INF;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)ans=min(ans,st[l++]);
        if(r&1)ans=min(ans,st[--r]);
    }
    return ans;
}
inline void stupdate(int node){
    int x=id[node]+n;
    st[x]=(INF+node)-st[x];
    for(;x>1;x>>=1)st[x>>1]=min(st[x],st[x^1]);
}

inline int query(int x){
    int ans=INF;
    while(x!=-1){
        ans=min(ans,stquery(id[head[x]],id[x]+1));
        x=parent[head[x]];
    }
    return ans==INF?-1:ans+1;
}


inline void update(int x){
    stupdate(x);
}

inline void debug(){
    cerr<<"depth: ";for(int i=0;i<n;i++)cerr<<depth[i]<<spc;cerr<<endl;
    cerr<<"sz: ";for(int i=0;i<n;i++)cerr<<sz[i]<<spc;cerr<<endl;
    cerr<<"parent: ";for(int i=0;i<n;i++)cerr<<parent[i]<<spc;cerr<<endl;
    cerr<<"heavy: ";for(int i=0;i<n;i++)cerr<<heavy[i]<<spc;cerr<<endl;
    cerr<<"head: ";for(int i=0;i<n;i++)cerr<<head[i]<<spc;cerr<<endl;
    cerr<<"id: ";for(int i=0;i<n;i++)cerr<<id[i]<<spc;cerr<<endl;
    cerr<<"st: ";for(int i=0;i<2*n;i++)cerr<<st[i]<<spc;cerr<<endl;

}

inline void solve(void){
    mset(heavy,-1);
    mset(head,-1);
    cin>>n>>q;
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
        if(x==1){
            cin>>x;
            cout<<query(x-1)<<endl;
            //cerr<<"query done\n";
        }
        else{
            cin>>x;
            update(x-1);
            //cerr<<"update done\n";
        }
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
