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
const int N=200005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans,start[N],endd[N],st[4*N],cnt;
vi v,adj[N];

inline void dfs(int node=0,int p=-1){
    //cerr<<"dfs: "<<node<<","<<p<<endl;
    start[node]=cnt;
    st[2*n+cnt++]=v[node];
    for(int& i:adj[node]){if(i!=p)dfs(i,node);}
    endd[node]=cnt;
    st[2*n+cnt++]=v[node];
}

inline void build(){
    for(int i=2*n-1;i>0;i--)st[i]=st[i*2]+st[i*2+1];
}

inline void update(int p,int val){
    for(st[p+=2*n]=val;p>1;p>>=1)st[p>>1]=st[p]+st[p^1];
}

inline int query(int l,int r){
    int ans=0;
    for(l+=2*n,r+=2*n;l<r;l>>=1,r>>=1){
        if(l&1)ans+=st[l++];
        if(r&1)ans+=st[--r];
    }
    return ans;
}

inline void solve(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){cin>>x;v.pb(x);}
    for(int i=1;i<n;i++){
        cin>>x>>y;
        x--,y--;
        adj[y].pb(x);
        adj[x].pb(y);
    }
    dfs();
    //cerr<<"dfs ok"<<endl;
    //cerr<<"start: ";for(int i=0;i<n;i++)cerr<<start[i]<<spc;cerr<<endl;
    //cerr<<"endd: ";for(int i=0;i<n;i++)cerr<<endd[i]<<spc;cerr<<endl;

    build();
    //cerr<<"build ok"<<endl;
    //cerr<<"st: ";for(int i=1;i<=4*n;i++)cerr<<st[i]<<spc;cerr<<endl;
    while(q--){
        cin>>x;
        if(x==1){
            cin>>x>>y;
            x--;
            update(start[x],y);
            update(endd[x],y);
            //cerr<<"update ok"<<endl;
            //cerr<<"st: ";for(int i=1;i<=4*n;i++)cerr<<st[i]<<spc;cerr<<endl;
        }
        else{
            cin>>x;
            x--;
            cout<<query(start[x],endd[x]+1)/2<<endl;
            //cerr<<"query ok"<<endl;
        }
    }
}

int32_t main(void){
    fastio;
    clock_t start=clock();
    solve();
    //while(clock()-start<=0.58*CLOCKS_PER_SEC);
}
