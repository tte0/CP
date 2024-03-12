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
const int N=200005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,ans;
vi v;

inline int solve(int n,const vi& v,const vi& v2){
    vii t(n);
    for(int i=1;i<=n;i++){
        x=v[i-1];
        t[x-1]={i,i};
    }
    for(int i=1;i<=n;i++){
        x=v2[i-1];
        t[x-1].ff=min(t[x-1].ff,i);
        t[x-1].ss=max(t[x-1].ss,i);
    }
    sort(all(t));
    vi dp(n+5,0);
    int updated=0;
    for(auto i:t){
        int l=i.ff,r=i.ss;
        for(;updated<l-1;updated++)dp[updated+1]=max(dp[updated+1],dp[updated]);
        dp[r]=max(dp[r],dp[l-1]+1);
    }
    return dp[n];
}

inline int bf(int n,const vi& v,const vi& v2){
    vvi dp(n+5,vi(n+5,0));
    dp[0][0]=(v[0]==v2[0]);
    for(int i=1;i<n;i++)dp[i][0]=max(dp[i-1][0],int(v[i]==v2[0]));
    for(int j=1;j<n;j++)dp[0][j]=max(dp[0][j-1],int(v[0]==v2[j]));
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=max({dp[i-1][j],dp[i][j-1],int(v[i]==v2[j])*(dp[i-1][j-1]+1)});
        }
    }
    return dp[n-1][n-1];
}

int32_t main(void){
    fastio;
    int t,n;
    cin>>t>>n;
    for(int i=1;i<=n;i++){
        vi v,v2;
        for(int i=1;i<=n;i++)v.pb(i);
        for(int i=1;i<=n;i++)v2.pb(i);
        random_shuffle(all(v));
        random_shuffle(all(v2));
        int ans1=solve(n,v,v2);
        int ans2=bf(n,v,v2);
        if(ans1!=ans2){
            cout<<endl<<"Wrong Answer on testcase "<<i<<endl;
            cout<<"Input:"<<endl;
            cout<<n<<endl;
            for(int i:v)cout<<i<<" ";cout<<endl;
            for(int i:v2)cout<<i<<" ";cout<<endl;
            cout<<"Answer:"<<endl;
            cout<<ans1<<endl;
            cout<<"Solution:"<<endl;
            cout<<ans2<<endl;
            return 0;
        }
    }
}
