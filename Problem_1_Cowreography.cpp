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
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
const int N=1e6+5;
const int MOD=1e9+7;
const i32 INF=INT32_MAX;
const ll  INFL=INT64_MAX;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,a,b,x,y,w,ans,cnt[N],cnt2[N];
str s,q;



inline void solve(void){
    cin>>n>>k>>s>>q;
    int p=0,p2=0,current=0,current2=0;
    for(int i=0;i<n;i++){
        //cerr<<"i: "<<i<<" -> "<<s[i]<<q[i]<<endl;
        if(s[i]=='1' && q[i]=='0')cnt[i]++,current++;
        if(q[i]=='1' && s[i]=='0')cnt2[i]++,current2++;
        //cerr<<"p,p2|c,c2: "<<p<<","<<p2<<"|"<<current<<","<<current2<<endl;
        //cerr<<"cnt: ";for(int _=max(int(0),i-8);_<=i+1;_++)cerr<<cnt[_];cerr<<endl;
        //cerr<<"cnt2: ";for(int _=max(int(0),i-8);_<=i+1;_++)cerr<<cnt2[_];cerr<<endl;
        while(current && current2){
            while(cnt[p]==0)p++;
            //cerr<<"p iterated"<<endl;
            while(cnt2[p2]==0)p2++;
            //cerr<<"p2 iterated"<<endl;
            int x=min(cnt[p],cnt2[p2]);
            ans+=x;
            cnt[p]-=x,cnt2[p2]-=x;
            current-=x,current2-=x;
            //cerr<<"p,p2|c,c2: "<<p<<","<<p2<<"|"<<current<<","<<current2<<endl;
        }
        if(i-k>=int(0)){
            cnt[i]+=cnt[i-k];
            ans+=cnt[i-k];
            cnt[i-k]=0;

            cnt2[i]+=cnt2[i-k];
            ans+=cnt2[i-k];
            cnt2[i-k]=0;
        }
        //cerr<<"p,p2|c,c2: "<<p<<","<<p2<<"|"<<current<<","<<current2<<endl;
        //cerr<<"cnt: ";for(int _=max(int(0),i-8);_<=i+1;_++)cerr<<cnt[_];cerr<<endl;
        //cerr<<"cnt2: ";for(int _=max(int(0),i-8);_<=i+1;_++)cerr<<cnt2[_];cerr<<endl;
        //cerr<<endl;
    }

    cout<<ans<<endl;
}

i32 main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
