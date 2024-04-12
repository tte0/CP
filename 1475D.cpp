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
const int N=200005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans;
vi v,adj[N];

inline void solve(void){
    cin>>n>>k;
    vi v,v1,v2;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==1)v1.pb(v[i]);
        else v2.pb(v[i]);
    }
    sort(rall(v1));
    sort(rall(v2));


    n=v1.size(),m=v2.size();
    /*int p1=0,p2=m-1,cnt=accumulate(all(v2),0),cost=2*v2.size(),ans=INF;
    while(true){
        //cerr<<"p1,p2|cnt,cost,ans : "<<p1<<","<<p2<<"|"<<cnt<<","<<cost<<","<<ans<<endl;
        if(cnt>=k){
            ans=min(ans,cost);
            if(p2<0)break;
            cost-=2;
            cnt-=v2[p2--];
        }
        else{
            if(p1>=n)break;
            cost++;
            cnt+=v1[p1++];
        }
    }
    //if(cnt>=k)ans=min(ans,cnt);

    cout<<ans<<endl;*/

    v1.insert(v1.begin(),0);
    v2.insert(v2.begin(),0);
    //cerr<<"v1: ";for(const int i:v1)cerr<<i<<" ";cerr<<endl;
    //cerr<<"v2: ";for(const int i:v2)cerr<<i<<" ";cerr<<endl;

    for(int i=1;i<=n;i++)v1[i]+=v1[i-1];
    for(int i=1;i<=m;i++)v2[i]+=v2[i-1];
    //cerr<<"v1: ";for(const int i:v1)cerr<<i<<" ";cerr<<endl;
    //cerr<<"v2: ";for(const int i:v2)cerr<<i<<" ";cerr<<endl;

    int ans=INF;
    for(int i=0;i<=n;i++){
        int x=v1[i];
        int y=lower_bound(all(v2),k-x)-v2.begin();
        if(y<=m)ans=min(ans,i+2*y);
        
        //cerr<<"ans: "<<ans<<endl;
    }

    cout<<(ans==INF?-1:ans)<<endl;
}

int32_t main(void){
    fastio;
    t=1;
    cin>>t;
    while(t--){
        solve();
        //cerr<<"testcase ok"<<endl;
    }
}
