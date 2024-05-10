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
#define Ey_Turk_gencligi__Birinci_vazifen__bu_definei_kodunun_sonuna_eklemendir  clock_t start=clock();while(clock()-start<=0.585*CLOCKS_PER_SEC)
using namespace std;
typedef int32_t i32;
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
typedef unordered_map<int,int> umii;
typedef unordered_map<char,int> umci;
typedef unordered_map<str,int> umsi;
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
inline void maxs(int& x,const int& y){return void(x=max(x,y));}
inline void mins(int& x,const int& y){return void(x=min(x,y));}
inline void gcds(int& x,const int& y){return void(x=gcd(x,y));}
inline void lcms(int& x,const int& y){return void(x=lcm(x,y));}
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
inline void debug(){cerr<<endl;}
template<typename... Args>
inline void debug(const Args&... args){
    ((cerr<<args<<' '),...)<<endl;
}
///////////////////////////////////////////////////////////////////
const int N=2e5+5;
const int A=1e9+5;
const int MOD=1e9+7;
const i32 INF=INT32_MAX;
const ll  INFL=INT64_MAX;
const ldouble EPS=1e-9;
const int MAXQUERY=100;
const double PI=4*atan(1);
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans;
vi v,adj[N];

class Manacher{
    private:
        int n=0,c=0;
        str s="",con;
        vi p,v,v2;
        void __con_init(){
            con="!#";
            for(int i=0;i<int(s.size());i++){
                con.pb(s[i]);
                con.pb('#');
            }
            con.pb('@');
            c=con.size();
            assert(c==(2*int(s.size())+3));
        }
        void __p_init(){
            p.assign(c,0);
            int l=1,r=1;
            for(int i=1;i<c;i++){
                maxs(p[i],min(r-i,p[l+r-i]));
                while(con[i-p[i]]==con[i+p[i]])p[i]++;
                if(r<i+p[i])l=i-p[i],r=i+p[i];
            }
            for(int i=0;i<c;i++)p[i]--;
            p.erase(p.begin());p.erase(p.begin());
            p.pop_back();p.pop_back();
            con.erase(con.begin());con.erase(con.begin());
            con.pop_back();con.pop_back();
            c-=4;
        }
        void __prefix_init(){
            for(int i=1;i<n;i++)if(s[i]!=s[i-1])v.pb(i-1);
            for(int i=2;i<n;i++)if(s[i]!=s[i-2])v2.pb(i-2);
        }
    public:
        Manacher(str input){
            s=input;
            n=s.size();

            __con_init();
            __p_init();
            __prefix_init();
        }
        bool isPalindrome(int l,int r){
            l--,r--;
            return p[l+r]>=(r-l+1);
        }
        void debug(){
            ::debug("n:",n);
            cerr<<"con: ";for(auto c:con)cerr<<c<<" ";cerr<<endl;
            ::debug("p:  ",p);
        }      
        void query(int l,int r){
            l--,r--;
            int sz=(r-l+1);
            if(sz==1)return print(0);
            if(sz==2)return print(2*(isPalindrome(l+1,r+1)?0:1));
            int ans=0;
            auto it=lower_bound(all(v),l);
            if(it!=v.end() && (*it)<=r){
                it=lower_bound(all(v2),l);
                if(it==v2.end() || (*it)>=r-1)ans=((sz-1)/2)*(((sz-1)/2)+1);
                else ans=sz*(sz-1)/2-1;
            }
            print(ans+sz*(isPalindrome(l+1,r+1)?0:1));
        } 
};


inline void test(str s){
    Manacher M(s);
    M.debug();
    for(int i=1;i<=int(s.size());i++)assert(M.isPalindrome(i,i));
    assert(!M.isPalindrome(1,5));
    assert(!M.isPalindrome(4,5));
    assert(!M.isPalindrome(5,6));
    assert(!M.isPalindrome(3,4));
    assert(M.isPalindrome(3,5));
}


inline void solve(void){
    str s;
    input(n,q,s);
    Manacher man(s);    
    
    while(q--){
        input(x,y);
        man.query(x,y);
    }
}

i32 main(void){
    #ifndef ONLINE_JUDGE
        test("aybabtu");
    #endif
    //fastio;
    t=1;
    cin>>t;
    while(t--)solve();
}
