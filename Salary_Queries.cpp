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
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#pragma GCC optimize("-fipa-sra,-fgcse-lm,-fgcse,inline,unroll-all-loops,no-stack-protector,O3,fast-math,Ofast")
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
#define fileio freopen("out.put","w",stdout);freopen("in.put","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
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
const int N=600005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,ans,st[4*N],arr[N];
str s;
vi v,cmp;
unordered_map<int,int> mp;

#define mid (l+r)/2

inline int build(int l,int r,int node){
    if(l==r)return st[node]=arr[l];
    return st[node]=build(l,mid,2*node)+build(mid+1,r,2*node+1);
}

inline int query(int l,int r,int node){
    //cerr<<"query: "<<l<<","<<r<<","<<node<<endl;

    if(x<=l && r<=y)return st[node];
    if(r<x || y<l)return 0;
    return query(l,mid,2*node)+query(mid+1,r,2*node+1);
}

inline int update(int l,int r,int node,int x,int y){
    //cerr<<"update: "<<l<<","<<r<<","<<node<<","<<x<<","<<y<<endl;

    if(r<x || x<l)return st[node];
    if(l==r){
        st[node]+=y;
        return st[node];
    }
    return st[node]=update(l,mid,2*node,x,y)+update(mid+1,r,2*node+1,x,y);
}

inline void solve(void){
    //input
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
        cmp.pb(x);
    }
    vector<pair<str,ii>> querys;
    for(int i=0;i<q;i++){
        cin>>s>>x>>y;
        querys.pb({s,{x,y}});
        if(s=="?")cmp.pb(x);
        cmp.pb(y);
    }
    //compress
    compress(cmp);
    for(int i=0;i<cmp.size();i++)mp[cmp[i]]=i+1;
    for(int i=0;i<n;i++)v[i]=mp[v[i]];
    for(int i=0;i<q;i++)querys[i].ss.ss=mp[querys[i].ss.ss];
    for(int i=0;i<q;i++)if(querys[i].ff=="?")querys[i].ss.ff=mp[querys[i].ss.ff];
    for(auto i:v)arr[i]++;

    //for(int i=0;i<n;i++)cerr<<v[i]<<",";cerr<<endl;
    //for(int i=0;i<q;i++)cerr<<querys[i].ff<<","<<querys[i].ss.ff<<","<<querys[i].ss.ss<<endl;
    //cerr<<"compress ok"<<endl;
    //st
    build(1,600000,1);
    //cerr<<"st[1]: "<<st[1]<<endl;
    //cerr<<"build ok"<<endl;
    for(int i=0;i<q;i++){
        s=querys[i].ff,x=querys[i].ss.ff,y=querys[i].ss.ss;
        if(s=="?"){
            cout<<query(1,600000,1)<<endl;
            //cerr<<"query ok"<<endl;
        }
        else{
            update(1,600000,1,v[x-1],-1);
            update(1,600000,1,y,1);
            v[x-1]=y;
            //cerr<<"update ok"<<endl;
        }
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
