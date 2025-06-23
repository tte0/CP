/*
Author: Teoman Ata Korkmaz
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define int ll
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
#define clz(x) __builtin_clz(x)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define clock() (chrono::high_resolution_clock::now().time_since_epoch().count())
#define compress(x) sort(all(x));x.resize(unique(all(x))-x.begin())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);cout<<fixed<<setprecision(0);cerr<<fixed<<setprecision(0)
#define fileio freopen("out.txt","w",stdout);freopen("in.txt","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
//using namespace __gnu_pbds;
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
template<typename InputIterator,typename T = int>
T accumulate(InputIterator first,InputIterator last,T init = T{}) {
    for (; first != last; ++first) {
        init += *first;
    }
    return init;
}
template<typename T,typename T2>inline pair<T,T2> operator+(const pair<T,T2>&a,const pair<T,T2>& b){return {a.ff+b.ff,a.ss+b.ss};}
template<typename T,typename T2>inline pair<T,T2> operator-(const pair<T,T2>&a,const pair<T,T2>& b){return {a.ff-b.ff,a.ss-b.ss};}
template<typename T,typename T2>inline pair<T,T2> operator*(const pair<T,T2>&a,const pair<T,T2>& b){return {a.ff*b.ff,a.ss*b.ss};}
template<typename T,typename T2>inline pair<T,T2> operator/(const pair<T,T2>&a,const pair<T,T2>& b){return {a.ff/b.ff,a.ss/b.ss};}
template<typename T> inline void maxs(T& x,const T& y){return void(x=max(x,y));}
template<typename T> inline void mins(T& x,const T& y){return void(x=min(x,y));}
template<typename T> inline void gcds(T& x,const T& y){return void(x=gcd(x,y));}
template<typename T> inline void lcms(T& x,const T& y){return void(x=lcm(x,y));}
template<typename T,typename T2>inline ostream& operator<<(ostream& os, const pair<T,T2>& p){
    os<<"["<<p.ff<<","<<p.ss<<"]";
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const vector<T>& a) {
    for(const T& _:a)os<<_<<' ';
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const vector<vector<T>>& a) {
    for(const vector<T>& _:a)os<<_;
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const set<T>& a) {
    for(const T& _:a)os<<_<<' ';
    return os;
}
template<typename T,typename T2>inline ostream& operator<<(ostream& os,const map<T,T2>& a) {
    for(const auto& _:a)os<<_<<' ';
    return os;
}
template<typename T,typename T2>inline ostream& operator<<(ostream& os,const unordered_map<T,T2>& a) {
    for(const auto& _:a)os<<_<<' ';
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const queue<T>& b) {
    queue<T> a=b;
    while(a.size()){
        os<<a.front()<<" ";
        a.pop();
    }
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const stack<T>& b) {
    stack<T> a=b;
    while(a.size()){
        os<<a.top()<<" ";
        a.pop();
    }
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const priority_queue<T>& b) {
    priority_queue<T> a=b;
    while(a.size()){
        os<<a.top()<<" ";
        a.pop();
    }
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const priority_queue<T,vector<T>,greater<T>>& b) {
    priority_queue<T,vector<T>,greater<T>> a=b;
    while(a.size()){
        os<<a.top()<<" ";
        a.pop();
    }
    return os;
}
template<typename T,typename T2>inline istream& operator>>(istream& is,pair<T,T2>& p){
    is>>(p.ff)>>(p.ss);
    return is;
}
template<typename T>inline istream& operator>>(istream& is,vector<T>& a) {
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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
mt19937 mt(clock());
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans;

inline int rand(int l,int r){
    return mt()%(r-l+1)+l;
}

inline string rand_str(int n){
    string s(n,'!');
    for(auto& c:s)c=rand('a','z');
    return s;
}

signed main(void){
    q=1000;
    print(q);
    for(int i=0;i<q;i++){
        if(i%2==0){
            print(1,rand_str(rand(1,4)+rand(1,4)));
        }
        else{
            print(2,rand_str(rand(1,10)));
        }
    }
}
