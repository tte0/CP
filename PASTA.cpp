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
#pragma GCC target("popcnt,abm,mmx,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#pragma GCC optimize("-fipa-sra,-fgcse-lm,-fgcse,inline,unroll-all-loops,no-stack-protector,O3,fast-math,Ofast")
#include <bits/stdc++.h>
#define int int_fast32_t
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
#define reverse(x) reverse(all(x));
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
#define fileio freopen("out.put","w",stdout);freopen("in.put","r",stdin)
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
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
//////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,ans,sieve[3*N/2],prefix[3*N/2][182];
vii v;

inline void initSieve(){
    mset(sieve,-1);
    sieve[0]=sieve[1]=1;
    for(int i=2;i<3*N/2;i++){
        if(sieve[i]!=-1)continue;
        sieve[i]=i;
        for(int j=i*i;j<3*N/2;j+=i)if(sieve[j]==-1)sieve[j]=i;
    }
}

inline bool cmp(ii a,ii b){
    if(a.ss!=b.ss)return a.ss<b.ss;
    return a.ff<b.ff;
}

inline void solve(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.pb({-1,y});
        int cnt=0,p=-1,ans=1;
        while(x>1){
            if(sieve[x]!=p){
                ans*=(cnt)+1;
                p=sieve[x],
                cnt=0;
            }
            cnt++;
            x/=sieve[x];
        }
        ans*=(cnt)+1;
        v.back().ff=ans;
    }
    sort(all(v),cmp);
    for(int i=0;i<n;i++)prefix[i+1][v[i].ff]++;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=180;j++)prefix[i][j]+=prefix[i-1][j];
    }
    
    vi arr;
    for(auto i: v)arr.pb(i.ss);
    while(q--){
        cin>>x>>y>>a>>b;
        x=min(x,(int)181);
        y=min(y,(int)181);
        int ind1=lower_bound(all(arr),a)-arr.begin();
        int ind2=upper_bound(all(arr),b)-arr.begin();
        int ans=0;
        for(int i=x;i<=y;i++)ans+=prefix[ind2][i]-prefix[ind1][i];
        cout<<ans<<endl;
    }
}

int32_t main(void){
    clock_t start=clock();
    fastio;
    initSieve();
    t=1;
    //cin>>t;
    while(t--)solve();
    //cout<<(clock()-start)/(CLOCKS_PER_SEC/1000);
}
