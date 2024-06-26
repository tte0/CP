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
const int N=200005;
const int MOD=1000000007;
const ll  INF=4e12;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,ans,st[4*N],lazy[4*N];
vi v,prefix;

#define mid ((l+r)/2)

inline int build(int l,int r,int node){
    if(l==r)return st[node]=prefix[l-1];
    return st[node]=max(build(l,mid,2*node),build(mid+1,r,2*node+1));
}

inline void push(int l,int r,int node){
    st[node]+=lazy[node];
    if(l<r){
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
}

inline int update(int l,int r,int node){
    push(l,r,node);
    if(r<x)return st[node];
    if(x<=l){
        lazy[node]+=y;
        push(l,r,node);
        return st[node];
    }
    return st[node]=max(update(l,mid,2*node),update(mid+1,r,2*node+1));
}

inline int query(int l,int r,int node){
    //cerr<<"query: "<<l<<","<<r<<","<<node<<endl;

    push(l,r,node);
    if(r<x || y<l)return -INF;
    if(x<=l && r<=y)return st[node];
    return max(query(mid+1,r,2*node+1),query(l,mid,2*node));
}

inline void solve(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    prefix=v;
    for(int i=1;i<n;i++)prefix[i]+=prefix[i-1];
    build(1,n,1);
    //cerr<<"prefix: ";for(int i=0;i<n;i++)cerr<<prefix[i]<<spc;cerr<<endl;
    //cerr<<"st: ";for(int i=1;i<16;i++)cerr<<st[i]<<spc;cerr<<endl;
    //cerr<<"build ok"<<endl;

    while(q--){
        cin>>x;
        if(x==1){
            cin>>x>>y;
            y=y-v[x-1];
            v[x-1]+=y;
            update(1,n,1);
            //cerr<<"update ok"<<endl;
        }
        else{
            cin>>x>>y;
            int ans=query(1,n,1);
            x--;y=x;
            ans-=x==0?0:query(1,n,1);
            cout<<max(int(0),ans)<<endl;

            //cerr<<"query ok"<<endl;
        }
        //cerr<<"v: ";for(int i=0;i<n;i++)cerr<<v[i]<<spc;cerr<<endl;
        //cerr<<"st: ";for(int i=1;i<16;i++)cerr<<st[i]<<spc;cerr<<endl;
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
