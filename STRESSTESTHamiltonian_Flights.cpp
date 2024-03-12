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
#define lcm(x,y) ((x*y)/gcd(x,y))
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
const int N=20;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int t,k,n,m,x,y,ans;
vi v;

inline int solve(const int& n,const int& m,const vvi& adj){
    vvi dp(n,vi(e2(n),0));
    vvi vis(n,vi(e2(n),0));
    queue<ii> q;
    q.push({0,1});
    dp[0][1]=1;
    while(q.size()){
        int node=q.front().ff,bm=q.front().ss;q.pop();
        if(vis[node][bm])continue;
        vis[node][bm]=1;
        //cerr<<"node,bm: "<<node<<","<<bm<<endl;
        for(auto i:adj[node]){
            if((bm&e2(i))==0){
                dp[i][bm|e2(i)]+=dp[node][bm];
                dp[i][bm|e2(i)]%=MOD;
                q.push({i,bm|e2(i)});
            }
        }
    }
    return dp[n-1][e2(n)-1];
}

inline int f(int node,int bm,const vvi& adj,vvi& dp){
    //cerr<<"f: "<<node<<","<<bm<<endl;
    if(node==n-1 && bm==e2(n)-1){/*cerr<<"ok"<<endl;*/return 1;}
    if(dp[node][bm]!=-1)return dp[node][bm];
    dp[node][bm]=0;
    for(auto i:adj[node]){
        if(!(bm&e2(i))){
        dp[node][bm]+=f(i,bm|e2(i),adj,dp);
        dp[node][bm]%=MOD;
        }
    }
    return dp[node][bm];
}
inline int bf(const int& n,const int& m,const vvi& adj){
    vvi dp(n,vi(e2(n),-1));
    return f(0,1,adj,dp);
}


inline void generateTestcase(vvi& adj){
    if(k==0){
        for(int i=1;i<=m;i++){
            int x=rand()%n;
            int y=rand()%n;
            adj[x].pb(y);
        }
    }
    if(k==1){
        vii v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                v.pb({i,j});
            }
        }
        random_shuffle(all(v));
        for(int i=0;i<m;i++){
            adj[v[i].ff].pb(v[i].ss);
        }
    }
    if(k==2){
        for(int i=0;i<n-1;i++)adj[i].pb(i+1);
        m-=n-1;
        for(int i=1;i<=m;i++){
            int x=rand()%n;
            int y=rand()%n;
            adj[x].pb(y);
        }
    }
}

int32_t main(void){/*
    k=0; complete random
    k=1; no-dupe random
    k=2; path+random
*/
    srand(time(NULL));
    fastio;
    cin>>t>>n>>m>>k;
    for(int _t=1;_t<=t;_t++){
        vvi adj(n);
        generateTestcase(adj);
        int ans=solve(n,m,adj);
        int sol=bf(n,m,adj);
        if(ans!=sol){
            cout<<"Wrons Answer on test "<<_t<<endl;
            cout<<"Input:"<<endl;
            cout<<n<<" "<<m<<endl;
            for(int i=0;i<n;i++)for(auto j:adj[i])cout<<i+1<<" "<<j+1<<endl;
            cout<<"Answer:"<<endl<<ans<<endl<<"Solution:"<<endl<<sol<<endl;
            return 0;
        }
    }
    cout<<"no problemo!"<<endl;
}
