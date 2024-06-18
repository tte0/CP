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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);cout<<fixed<<setprecision(0);cerr<<fixed<<setprecision(0)
#define fileio freopen("out.txt","w",stdout);freopen("in.txt","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
#define ASSERT(condition,message) if(!condition){debug("Assertion failed:",message);abort();}
using namespace std;
typedef int32_t i32;
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
typedef map<int,vi> miv;
typedef unordered_map<int,int> umii;
typedef unordered_map<char,int> umci;
typedef unordered_map<str,int> umsi;
typedef unordered_map<int,vi> umiv;
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
inline int segsum(int start,int end,int step){
    if(end<start)return 0;
    return (((end-start)/step+1)*(start+end))>>1;
}
inline int fp(int b,int p,int mod=1e9+7){
    int ans=1;
    while(p){
        if(p&1)ans=(ans*b)%mod;
        p>>=1;
        b=(b*b)%mod;
    }
    return ans;
}
template<typename T> inline void maxs(T& x,const T& y){return void(x=max(x,y));}
template<typename T> inline void mins(T& x,const T& y){return void(x=min(x,y));}
template<typename T> inline void gcds(T& x,const T& y){return void(x=gcd(x,y));}
template<typename T> inline void lcms(T& x,const T& y){return void(x=lcm(x,y));}
template<typename T,typename T2>
inline ostream& operator<<(ostream& os, const pair<T,T2>& p){
    os<<p.ff<<","<<p.ss<<endl;
    return os;
}
template<typename T>
inline ostream& operator<<(ostream& os,const vector<T>& a) {
    for(const T& _:a)os<<_<<' ';
    return os;
}
template<typename T>
inline ostream& operator<<(ostream& os,const vector<vector<T>>& a) {
    for(const vector<T>& _:a)os<<_<<endl;
    return os;
}
template<typename T>
inline ostream& operator<<(ostream& os,const set<T>& a) {
    for(const T& _:a)os<<_<<' ';
    return os;
}
template<typename T,typename T2>
inline ostream& operator<<(ostream& os,const map<T,T2>& a) {
    for(const auto& _:a)os<<_<<' ';
    return os;
}
template<typename T,typename T2>
inline ostream& operator<<(ostream& os,const unordered_map<T,T2>& a) {
    for(const auto& _:a)os<<_<<' ';
    return os;
}
template<typename T,typename T2>
inline istream& operator>>(istream& is,pair<T,T2>& p){
    is>>(p.ff)>>(p.ss);
    return is;
}
template<typename T>
inline istream& operator>>(istream& is,vector<T>& a) {
    for(T& _:a)is>>_;
    return is;
}
inline void print(){cout<<endl;}
template<typename... Args>
inline void print(const Args&... args){
    ((cout<<args<<' '),...)<<endl;
}
inline void input(){}
template<typename... Args>
inline void input(Args&... args){
    (cin>>...>>args);
}
#ifdef ONLINE_JUDGE
template<typename... Args>
inline void debug(const Args&... args){
    return void("59");
}
#else
inline void debug(){cerr<<endl;}
template<typename... Args>
inline void debug(const Args&... args){
    ((cerr<<args<<' '),...)<<endl;
}
#endif
inline void yn(bool b){
    if(b)yes;
    else no;
}
///////////////////////////////////////////////////////////////////
const int N=2e5+5;
const int A=1e9+5;
const int MOD=1e9+7;
const i32 INF=INT32_MAX;
const ll  INFL=INT64_MAX;
const int BLOCK=320;
const ldouble EPS=1e-9;
const int MAXQUERY=100;
const double PI=4*atan(1);
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans;
vi v,adj[N];

inline void solve(void){
    input(n,k);
    v.resize(n);
    input(v);
    v[0]+=k;

    vi prefix=v,sobv(n,-1);
    vii a;
    for(int i=1;i<n;i++)prefix[i]+=prefix[i+1];
    for(int i=0;i<n;i++)a.pb({v[i],i});
    sort(rall(a));
    int sum=0;
    for(auto i:a){
        sobv()
    }
}

i32 main(void){
    fastio;
    //usacoio("59");
    t=1;
    //cin>>t;
    while(t--)solve();
}
