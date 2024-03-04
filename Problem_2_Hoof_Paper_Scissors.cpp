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
#define usacoio(a,b) freopen(b,"w",stdout);freopen(a,"r",stdin)
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
int n,m,k,t,q,a,b,x,y,ans;
char c;
vi v;

inline void solve(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='P')v.pb(0);
        if(c=='H')v.pb(1);
        if(c=='S')v.pb(2);
    }
    vvvi dp(n+5,vvi(k+5,vi(3,0)));
    if(v[0]==0)dp[0][0][0]=1;
    if(v[0]==1)dp[0][0][1]=1;
    if(v[0]==2)dp[0][0][2]=1;

    for(int i=1;i<n;i++){
        dp[i][0][0]=dp[i-1][0][0]+(v[i]==0);
        dp[i][0][1]=dp[i-1][0][1]+(v[i]==1);
        dp[i][0][2]=dp[i-1][0][2]+(v[i]==2);
        for(int j=1;j<=k;j++){
            dp[i][j][0]=max({dp[i-1][j][0],dp[i-1][j-1][1],dp[i-1][j-1][2]})+(v[i]==0);
            dp[i][j][1]=max({dp[i-1][j-1][0],dp[i-1][j][1],dp[i-1][j-1][2]})+(v[i]==1);
            dp[i][j][2]=max({dp[i-1][j-1][0],dp[i-1][j-1][1],dp[i-1][j][2]})+(v[i]==2);
        }
    }
    int ans=0;
    for(int i=0;i<=k;i++)ans=max({ans,dp[n-1][i][0],dp[n-1][i][1],dp[n-1][i][2]});
    cout<<ans;
}

int32_t main(void){
    fastio;
    usacoio("hps.in","hps.out");
    t=1;
    //cin>>t;
    while(t--)solve();
}
