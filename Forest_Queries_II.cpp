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
#define int i32
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define e2(x) (1LL<<(x))
#define lg(x) (__lg(x))
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
#define clock() (chrono::high_resolution_clock::now().time_since_epoch().count())
#define compress(x) sort(all(x));x.resize(unique(all(x))-x.begin())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);cout<<fixed<<setprecision(0);cerr<<fixed<<setprecision(0)
#define fileio freopen("out.txt","w",stdout);freopen("in.txt","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
typedef int_fast32_t i32;
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
typedef vector<str> vstr;
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
    os<<"["<<p.ff<<","<<p.ss<<"]";
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
template<typename T>
inline ostream& operator<<(ostream& os,const queue<T>& b) {
    queue<T> a=b;
    while(a.size()){
        os<<a.front()<<" ";
        a.pop();
    }
    return os;
}
template<typename T>
inline ostream& operator<<(ostream& os,const stack<T>& b) {
    stack<T> a=b;
    while(a.size()){
        os<<a.top()<<" ";
        a.pop();
    }
    return os;
}
template<typename T>
inline ostream& operator<<(ostream& os,const priority_queue<T>& b) {
    priority_queue<T> a=b;
    while(a.size()){
        os<<a.top()<<" ";
        a.pop();
    }
    return os;
}
template<typename T>
inline ostream& operator<<(ostream& os,const priority_queue<T,vector<T>,greater<T>>& b) {
    priority_queue<T,vector<T>,greater<T>> a=b;
    while(a.size()){
        os<<a.top()<<" ";
        a.pop();
    }
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
#define ASSERT(condition, message)\
if(condition){\
    cerr<<"Assertion failed: "<<message<<" at "<<__FILE__<<":"<<to_string(__LINE__)<<endl;\
    abort();\
}\
///////////////////////////////////////////////////////////////////
const int N=1005;
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
mt19937 mt(clock());
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,u,d,l,r,w,ans,st[2*N][2*N];
vstr s;

inline void build(){
    for(int i=n;i<2*n;i++){
        for(int j=n;j<2*n;j++)st[i][j]=(s[i-n][j-n]=='*');
        for(int j=n-1;j>0;j--)st[i][j]=st[i][j<<1]+st[i][j<<1|1];
    }
    for(int i=n-1;i>0;i--){
        for(int j=1;j<2*n;j++)st[i][j]=st[i<<1][j]+st[i<<1|1][j];
    }
}

inline void update(){
    st[x][y]=1-st[x][y];
    for(int j=y;j>1;j>>=1)st[x][j>>1]=st[x][j]+st[x][j^1];
    for(int i=x;i>1;i>>=1){
        for(int j=y;j>0;j>>=1){
            st[i>>1][j]=st[i][j]+st[i^1][j];
        }
    }
}

inline int query(){
    int ans=0;
    for(int u=::u+n,d=::d+n;u<d;u>>=1,d>>=1){
        if(u&1){
            //ans+=st[u++];
            for(int l=::l+n,r=::r+n;l<r;l>>=1,r>>=1){
                if(l&1)ans+=st[u][l++];
                if(r&1)ans+=st[u][--r];
            }
            u++;
        }
        if(d&1){
            --d;
            for(int l=::l+n,r=::r+n;l<r;l>>=1,r>>=1){
                if(l&1)ans+=st[d][l++];
                if(r&1)ans+=st[d][--r];
            }
            //ans+=st[--d];
        }
    }
    return ans;
}

inline void solve(void){
    input(n,q);
    s.resize(n);
    input(s);

    build();
    
    while(q--){
        input(x);
        if(x==1){
            input(x,y);
            --x+=n,--y+=n;
            update();
        }
        else{
            input(u,l,d,r);
            u--,l--;
            print(query());
        }
    }
}

signed main(void){
    fastio;
    //usacoio("59");
    int t=1;
    //cin>>t;
    while(t--)solve();
}
