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
int n,m,k,t,a,b,x,y,ans;

inline int dist(ii a,ii b){
    return (abs(a.ff-b.ff)+abs(a.ss-b.ss))*(abs(a.ff-b.ff)+abs(a.ss-b.ss));
}

inline int solve(int n,int m,int x,int y,int a,int b,str s,str q){//nsew
    vii v,v2;
    v.pb({x,y});
    for(int i=0;i<n;i++){
        switch (s[i]){
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }
        v.pb({x,y});
    }

    v2.pb({a,b});
    for(int i=0;i<m;i++){
        switch (q[i]){
            case 'N': b++; break;
            case 'S': b--; break;
            case 'E': a++; break;
            case 'W': a--; break;
        }
        v2.pb({a,b});
    }

    vvi dp(n+5,vi(m+5,INF));
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i!=0)dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(j!=0)dp[i][j]=min(dp[i][j],dp[i][j-1]);
            if(i!=0 && j!=0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            if(i!=0 || j!=0)dp[i][j]+=dist(v[i],v2[j]);
        }
    }

    /*for(int i=0;i<=n;i++){
        cerr<<"dp: ";
        for(int j=0;j<=m;j++)cerr<<dp[i][j]<<",";
        cerr<<endl;
    }*/
    return dp[n][m];
}

inline int f(int ind,int jnd,vii& v,vii& v2,vvi& dp){
    if(ind==n && jnd==m)return 0;
    if(ind>n && jnd>m)return INF;
    if(dp[ind][jnd]!=INF)return dp[ind][jnd];
    
    if(ind<n)dp[ind][jnd]=min(dp[ind][jnd],f(ind+1,jnd,v,v2,dp)+dist(v[ind+1],v2[jnd]));
    if(jnd<m)dp[ind][jnd]=min(dp[ind][jnd],f(ind,jnd+1,v,v2,dp)+dist(v[ind],v2[jnd+1]));
    if(ind<n && jnd<m)dp[ind][jnd]=min(dp[ind][jnd],f(ind+1,jnd+1,v,v2,dp)+dist(v[ind+1],v2[jnd+1]));
    return dp[ind][jnd];
}

inline int bf(int n,int m,int x,int y,int a,int b,str s,str q){
    vii v,v2;
    v.pb({x,y});
    for(int i=0;i<n;i++){
        switch (s[i]){
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }
        v.pb({x,y});
    }

    v2.pb({a,b});
    for(int i=0;i<m;i++){
        switch (q[i]){
            case 'N': b++; break;
            case 'S': b--; break;
            case 'E': a++; break;
            case 'W': a--; break;
        }
        v2.pb({a,b});
    }

    vvi dp(n+5,vi(m+5,INF));
    return f(0,0,v,v2,dp);
}

int32_t main(void){
    srand(time(NULL));
    t=1;
    cin>>t>>n>>m>>x>>y>>a>>b;
    while(t--){
        str s,q;
        for(int i=0;i<n;i++){
            int r=rand()%4;
            switch (r){
            case 0:s.pb('N');break;
            case 1:s.pb('S');break;
            case 2:s.pb('E');break;
            case 3:s.pb('W');break;
            }
        }
        for(int i=0;i<m;i++){
            int r=rand()%4;
            switch (r){
            case 0:q.pb('N');break;
            case 1:q.pb('S');break;
            case 2:q.pb('E');break;
            case 3:q.pb('W');break;
            }
        }

        int solveans=solve(n,m,x,y,a,b,s,q);
        int bfans=bf(n,m,x,y,a,b,s,q);
        if(bfans!=solveans){
            cout<<n<<" "<<m<<endl<<x<<" "<<y<<endl<<a<<" "<<b<<endl<<s<<endl<<q<<endl<<"solve: "<<solveans<<"\nbf: "<<bfans<<endl;
            cerr<<t;
            return 0;
        }
    }
    cout<<"no problemo!";
}
