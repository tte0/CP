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
#pragma GCC optimize("O3,fast-math")
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
#define fileio freopen("out.put","w",stdout);freopen("in.put","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
using namespace std;
typedef int_fast64_t ll;
typedef long double ldouble;
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
typedef set<int> sti;
typedef set<char> stc;
typedef multiset<int> msti;
typedef multiset<char> mstc;
const int N=200005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,ans,st[4*N],sts[4*N],str[4*N],stl[4*N];
vi v;

#define mid (l+r)/2

inline void nodeUpdate(int node){
    st[node]=max({int(0),st[2*node],st[2*node+1],stl[2*node+1]+str[2*node]});
    sts[node]=sts[2*node]+sts[2*node+1];
    stl[node]=max({int(0),stl[2*node],sts[2*node]+stl[2*node+1]});
    str[node]=max({int(0),str[2*node+1],sts[2*node+1]+str[2*node]});
}

inline void build(int l,int r,int node){
    if(l==r){
        st[node]=stl[node]=str[node]=max(int(0),v[l-1]);
        sts[node]=v[l-1];
        return;
    }
    build(l,mid,2*node);
    build(mid+1,r,2*node+1);
    nodeUpdate(node);
    return;
}

inline void update(int l,int r,int node){
    if(r<x || x<l)return;
    if(l==r){
        st[node]=stl[node]=str[node]=max(int(0),y);
        sts[node]=y;
        return;
    }
    update(l,mid,2*node);
    update(mid+1,r,2*node+1);
    nodeUpdate(node);
    return;
}

inline void solve(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    build(1,n,1);

    //cerr<<"st: ";for(int i=1;i<16;i++)cerr<<st[i]<<spc;cerr<<endl;
    //cerr<<"sts: ";for(int i=1;i<16;i++)cerr<<sts[i]<<spc;cerr<<endl;
    //cerr<<"stl: ";for(int i=1;i<16;i++)cerr<<stl[i]<<spc;cerr<<endl;
    //cerr<<"str: ";for(int i=1;i<16;i++)cerr<<str[i]<<spc;cerr<<endl;

    while(q--){
        cin>>x>>y;
        update(1,n,1);
        cout<<st[1]<<endl;
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
