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
const int N=1e5+5;
const int A=e2(21);
const int MOD=1e9+7;
const int BLOCK=320;
const i32 INF=INT32_MAX;
const ll  INFL=INT64_MAX;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
inline void maxs(int& x,const int& y){return void(x=max(x,y));}
inline void mins(int& x,const int& y){return void(x=min(x,y));}
///////////////////////////////////////////////////////////////////
int n,k,t,q,x,y,cnt[A],ans[N];
vi v={0};

inline bool cmp(const iii& a,const iii& b){
    if(a.ss.ff/BLOCK != b.ss.ff/BLOCK)return a.ss.ff<b.ss.ff;
    return a.ss.ss<b.ss.ss;
}

inline void solve(void){
    cin>>n>>q>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(v.back()^x);
    }
    viii query;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        query.pb({i,{x,y}});
    }
    sort(all(query),cmp);
    //cerr<<"sort ok"<<endl;
    //for(const iii& _:query)cerr<<"query: i,x,y > "<<_.ff+1<<" "<<_.ss.ff<<" "<<_.ss.ss<<endl;


    int current_ans=(k==v[1]),l=1,r=1;
    cnt[v[0]]++;
    cnt[v[1]]++;
    for(const iii& _:query){//[l,r] -> pref[l-1,r] 
        int x=_.ss.ff,y=_.ss.ss,ind=_.ff;
        //cerr<<"query: x,y > "<<x<<" "<<y<<endl;
        //cerr<<"l,r,ans > "<<l<<" "<<r<<" "<<current_ans<<endl;
        while(r<y){//expand r
            r++;
            current_ans+=cnt[(v[r]^k)];
            cnt[v[r]]++;
        }
        //cerr<<"l,r,ans > "<<l<<" "<<r<<" "<<current_ans<<endl;
        while(x<l){//expand l
            l--;
            current_ans+=cnt[(v[l-1]^k)];
            cnt[v[l-1]]++;
        }
        //cerr<<"l,r,ans > "<<l<<" "<<r<<" "<<current_ans<<endl;
        while(y<r){//shrink r
            cnt[v[r]]--;
            current_ans-=cnt[(v[r]^k)];
            r--;
        }
        //cerr<<"l,r,ans > "<<l<<" "<<r<<" "<<current_ans<<endl;
        while(l<x){//shrink l
            cnt[v[l-1]]--;
            current_ans-=cnt[(v[l-1]^k)];
            l++;
        }
        //cerr<<"l,r,ans > "<<l<<" "<<r<<" "<<current_ans<<endl;
        ans[ind]=current_ans;

        //cerr<<"query ok"<<endl;
    }
    for(int i=0;i<q;i++)cout<<ans[i]<<endl;
}

i32 main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
