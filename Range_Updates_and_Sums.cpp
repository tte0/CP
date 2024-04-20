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
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,k,t,q,a,b,x,y,w,ans,st[4*N],lazy[4*N]={false};
bool lazy2[N];//true -> set | false -> add
vi v={0},adj[N];

#define m ((l+r)/2)

inline int build(int l=1,int r=n,int node=1){
    return st[node]=(l==r?v[l]:build(l,m,2*node)+build(m+1,r,node*2+1));
}

inline void push(int l,int r,int node){
    if(lazy2[node])st[node]=(r-l+1)*lazy[node];
    else st[node]+=(r-l+1)*lazy[node];
    if(l!=r){
        if(lazy2[node]){
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
            lazy2[node*2]=lazy2[node*2+1]=lazy2[node];
        }
        else{
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
    }
    lazy[node]=lazy2[node]=0;
}

inline int update(int l=1,int r=n,int node=1){
    push(l,r,node);
    if(r<x || y<l)return st[node];
    if(x<=l && r<=y){
        lazy[node]+=w;
        push(l,r,node);
        return st[node];
    }
    return st[node]=update(l,m,2*node)+update(m+1,r,2*node+1);
}

inline int query(int l=1,int r=n,int node=1){
    //cerr<<"query: "<<l<<spc<<r<<spc<<node<<endl;
    push(l,r,node);
    if(r<x || y<l)return 0;
    if(x<=l && r<=y)return st[node];
    return query(l,m,2*node)+query(m+1,r,2*node+1);
}

inline int update2(int l=1,int r=n,int node=1){
    push(l,r,node);
    if(r<x || y<l)return st[node];
    if(x<=l && r<=y){
        lazy[node]=w;
        lazy2[node]=1;
        push(l,r,node);
        return st[node];
    }
    return st[node]=update2(l,m,2*node)+update2(m+1,r,2*node+1);
}

inline void fullpush(int l=1,int r=n,int node=1){
    push(l,r,node);
    if(l==r)return;
    fullpush(l,m,2*node);
    fullpush(m+1,r,2*node+1);
}

inline void solve(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    build();
    //cerr<<"build ok\n";
    //cerr<<"st: ";for(int i=1;i<=4*n;i++)cerr<<st[i]<<spc;cerr<<endl;
    while(q--){
        cin>>x;
        if(x==1){
            cin>>x>>y>>w;
            update();
            //cerr<<"update ok\n";
        }
        else if(x==3){
            cin>>x>>y;
            cout<<query()<<endl;
            //cerr<<"query ok\n";
        }
        else{
            cin>>x>>y>>w;
            update2();
            //cerr<<"update2 ok\n";
        }
        //fullpush();
        //cerr<<"st: ";for(int i=1;i<=4*n;i++)cerr<<st[i]<<spc;cerr<<endl;
        //cerr<<endl;
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
