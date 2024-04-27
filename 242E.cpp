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
const int BIT=20;
const int MOD=1e9+7;
const i32 INF=INT32_MAX;
const ll  INFL=INT64_MAX;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
inline void maxs(int& x,const int& y){return void(x=max(x,y));}
inline void mins(int& x,const int& y){return void(x=min(x,y));}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans,st[4*N][BIT],lazy[4*N][BIT];
vi v,adj[N];

#define mid ((l+r)/2)

inline int stbuild(int l,int r,int node,int bit){
    if(l==r)return st[node][bit]=(v[l-1]&e2(bit));
    return st[node][bit]=stbuild(l,mid,node*2,bit)+stbuild(mid+1,r,node*2+1,bit);
}

inline void build(){
    for(int i=0;i<BIT;i++)stbuild(1,n,1,i);
}

inline void push(int l,int r,int node,int bit){
    if(!lazy[node][bit])return;
    st[node][bit]=((r-l+1)*e2(bit))-st[node][bit];
    lazy[node][bit]=0;
    if(l==r)return;
    lazy[node*2][bit]^=1;
    lazy[node*2+1][bit]^=1;
}

inline int stquery(int l,int r,int node,int bit){
    push(l,r,node,bit);
    if(x<=l && r<=y)return st[node][bit];
    if(r<x || y<l)return 0;
    return stquery(l,mid,node*2,bit)+stquery(mid+1,r,node*2+1,bit);
}

inline int query(){
    int ans=0;
    for(int i=0;i<BIT;i++)ans+=stquery(1,n,1,i);
    return ans;
}

inline void stupdate(int l,int r,int node,int bit){
    push(l,r,node,bit);
    if(x<=l && r<=y){
        lazy[node][bit]=1;
        push(l,r,node,bit);
        return;
    }
    if(r<x || y<l)return;
    stupdate(l,mid,node*2,bit);
    stupdate(mid+1,r,node*2+1,bit);
    st[node][bit]=st[node*2][bit]+st[node*2+1][bit];    
}
    

inline void update(){
    for(int i=0;i<BIT;i++)if(w&e2(i))stupdate(1,n,1,i);
}

inline void solve(void){
    cin>>n;
    v.resize(n);
    for(int& i:v)cin>>i;

    build();

    cin>>q;
    while(q--){
        cin>>x;
        if(x==1){
            cin>>x>>y;
            cout<<query()<<endl;
        }
        else{
            cin>>x>>y>>w;
            update();
        }
    }
}

i32 main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
