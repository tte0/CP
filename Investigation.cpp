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
typedef pair<ii,ii> iiii;
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
const int MOD=1e9+7;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans;
vii adj[N];

inline void solve(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        adj[x].pb({y,w});
    }

    priority_queue<pair<int,iiii>,vector<pair<int,iiii>>,greater<pair<int,iiii>>> q;//cost,node,cnt,mn,mx
    q.push({int(0),{{int(1),int(1)},{int(0),int(0)}}});

    int current_cost=0;
    vi cost(n+1,INF),now(n+1,0),min_flight(n+1,INF),max_flight(n+1,-1);
    while(q.size()){
        vi bt;
        current_cost=q.top().ff;
        while(q.size() && q.top().ff==current_cost){
            auto t=q.top();q.pop();
            int c=t.ff,node=t.ss.ff.ff,cnt=t.ss.ff.ss,mn=t.ss.ss.ff,mx=t.ss.ss.ss;
            if(c>cost[node])continue;

            cost[node]=c;
            now[node]=(now[node]+cnt)%MOD;
            min_flight[node]=min(min_flight[node],mn);
            max_flight[node]=max(max_flight[node],mx);

            bt.pb(node);
        }
        compress(bt);
        for(auto node:bt){
            for(auto x:adj[node]){
                int y=x.ff,w=x.ss;
                q.push({cost[node]+w,{{y,now[node]},{min_flight[node]+1,max_flight[node]+1}}});
            }
        }
    }

    if(cost[n]==INF)cout<<-1<<endl;
    else cout<<cost[n]<<spc<<now[n]<<spc<<min_flight[n]<<spc<<max_flight[n]<<endl;

    /*cerr<<"cost now min max\n";
    for(int i=1;i<=n;i++){
        cerr<<i<<" > "<<cost[i]<<spc<<now[i]<<spc<<min_flight[i]<<spc<<max_flight[i]<<endl;
    }*/
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
