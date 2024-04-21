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
#pragma GCC optimize("O3,fast-math,unroll-all-loops")
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
#define compress(x) sort(all(x));x.resize(unique(all(x))-x.begin())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
#define fileio freopen("out.txt","w",stdout);freopen("in.txt","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
#define Ey_Turk_gencligi__Birinci_vazifen__bu_definei_kodunun_sonuna_eklemendir  clock_t start=clock();while(clock()-start<=0.585*CLOCKS_PER_SEC)
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
int n,m,k,t,q,a,b,x,y,w,pref[N],sparse[2*N][20],id[N],di[N],ind[N],idcnt;
vi v,adj[N],ett;
vii edges;
unordered_map<int,int> ans[N];

inline void dfs(int node=0,int p=-1){
    id[node]=idcnt;
    di[idcnt++]=node;
    ett.pb(id[node]);
    for(auto i:adj[node]){
        if(i==p)continue;
        ett.pb(id[node]);
        dfs(i,node);
    }
}

inline void build(){
    int n=ett.size();
    for(int i=0;i<n;i++)ind[ett[i]]=i;
    for(int i=0;i<n;i++)sparse[i][0]=ett[i];
    for(int j=1;j<20;j++){
        for(int i=0;i<n;i++){
            int x=i;
            int y=min(int(n-1),int(i+e2(j-1)));
            sparse[i][j]=min(sparse[x][j-1],sparse[y][j-1]);
        }
    }
}

inline int lca(int x,int y){
    x=ind[id[x]];
    y=ind[id[y]];
    if(x>y)swap(x,y);
    int dist=__lg(y-x+1);
    //cerr<<"indx,indy,dist: "<<x<<" "<<y<<" "<<dist<<endl;
    return di[min(sparse[x][dist],sparse[y-e2(dist)+1][dist])];
}

inline int dfs2(int node=0,int p=0){
    for(auto i:adj[node]){
        if(i==p)continue;
        pref[node]+=dfs2(i,node);
    }
    ans[node][p]=pref[node];
    ans[p][node]=pref[node];
    return pref[node];
}

inline void solve(void){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
        edges.pb({x,y});
    }
    dfs();
    //cerr<<"ett: ";for(auto i:ett)cerr<<i<<" ";cerr<<endl;
    //cerr<<"ett: ";for(auto i:ett)cerr<<di[i]<<" ";cerr<<endl;
    build();
    /*cerr<<"ind: ";for(int i=0;i<n;i++)cerr<<ind[i]<<" ";cerr<<endl;
    for(int j=0;j<20;j++){
        cerr<<"sparse: ";
        for(int i=0;i<2*n;i++)cerr<<sparse[i][j]<<" ";cerr<<endl;
    }*/
    cin>>q;
    while(q--){
        cin>>x>>y;
        x--,y--;
        int l=lca(x,y);
        //cerr<<"lca: "<<l+1<<endl;
        pref[x]++,pref[y]++,pref[l]-=2;
    }

    //cerr<<"pref: ";for(int i=0;i<n;i++)cerr<<pref[i]<<" ";cerr<<endl;
    dfs2();
    //cerr<<"pref: ";for(int i=0;i<n;i++)cerr<<pref[i]<<" ";cerr<<endl;

    for(int i=0;i<n-1;i++){
        cout<<ans[edges[i].ff][edges[i].ss]<<" ";
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
