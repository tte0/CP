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
const int MOD=1e9+7;
const i32 INF=INT32_MAX;
const ll  INFL=INT64_MAX;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
inline void maxs(int& x,const int& y){return void(x=max(x,y));}
inline void mins(int& x,const int& y){return void(x=min(x,y));}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans,sparseMax[N][20],sparseMin[N][20],leftMax[N],rightMax[N];
vi v,pref;

inline void sparseinit(){
    int n=pref.size();
    for(int i=0;i<n;i++)sparseMax[i][0]=sparseMin[i][0]=pref[i];
    for(int j=1;j<20;j++){
        for(int i=0;i<n;i++){
            sparseMax[i][j]=max(sparseMax[i][j-1],sparseMax[min(int(n-1),int(i+e2(j-1)))][j-1]);
            sparseMin[i][j]=min(sparseMin[i][j-1],sparseMin[min(int(n-1),int(i+e2(j-1)))][j-1]);
        }
    }
}

inline int querymin(int l,int r){
    l++,r++;
    if(r<l)cerr<<"r<l PATLADI (min)"<<endl;
    int dist=__lg(r-l+1);
    return min(sparseMin[l][dist],sparseMin[r-e2(dist)+1][dist]);
}

inline int querymax(int l,int r){
    l++,r++;
    if(r<l)cerr<<"r<l PATLADI (max)"<<endl;
    int dist=__lg(r-l+1);
    return max(sparseMax[l][dist],sparseMax[r-e2(dist)+1][dist]);
}

inline void solve(void){
    cin>>n;
    v.resize(n);
    for(int& i:v)cin>>i;
    pref=v;pref.insert(pref.begin(),0);
    for(int i=1;i<=n;i++)pref[i]+=pref[i-1];

    sparseinit();
    /*
    for(int j=0;j<20;j++){
        cerr<<"sparseMax: ";
        for(int i=0;i<n+1;i++)cerr<<sparseMax[i][j]<<" ";
        cerr<<endl;
    }
    for(int j=0;j<20;j++){
        cerr<<"sparseMin: ";
        for(int i=0;i<n+1;i++)cerr<<sparseMin[i][j]<<" ";
        cerr<<endl;
    }
    */
    leftMax[0]=-1;
    stack<int> s=stack<int>({0});
    for(int i=1;i<n;i++){
        while(s.size() && v[s.top()]<=v[i])s.pop();
        leftMax[i]=s.empty()?-1:s.top();
        s.push(i);
    }
    rightMax[n-1]=n;
    s=stack<int>({n-1});
    for(int i=n-2;i>=0;i--){
        while(s.size() && v[s.top()]<=v[i])s.pop();
        rightMax[i]=s.empty()?n:s.top();
        s.push(i);
    }

    //cerr<<"leftMax: ";for(int i=0;i<n;i++)cerr<<leftMax[i]<<" ";cerr<<endl;
    //cerr<<"rightMax: ";for(int i=0;i<n;i++)cerr<<rightMax[i]<<" ";cerr<<endl;

    for(int i=0;i<n;i++){//     -min([pref[l],pref[i-1]])+max(pref[i],pref[r-1])
        int l=leftMax[i],r=rightMax[i];
        //if(l==r)continue;//     can/wil be removed 
        int x=-v[i];
        x-=querymin(l,i-1);
        x+=querymax(i,r-1);

        maxs(ans,x);
        //cerr<<"ans: "<<ans<<endl;
    }

    cout<<ans<<endl;
}

i32 main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
