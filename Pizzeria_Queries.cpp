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
#define wait while(clock()-start<=0.585*CLOCKS_PER_SEC);
using namespace std;
typedef int_fast64_t ll;
typedef vector<int> vi;
const int N=200005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans,stl[4*N],str[4*N];
vi v;

#define mid ((l+r)/2)

inline void calculateNode(int node){
    stl[node]=min(stl[node*2],stl[node*2+1]);
    str[node]=min(str[node*2],str[node*2+1]);
}

inline void build(int l=1,int r=n,int node=1){
    //cerr<<"build: "<<l<<spc<<r<<spc<<node<<endl;
    if(l==r){
        stl[node]=v[l-1]+(n-l);
        str[node]=v[l-1]+l;
        return;
    }
    build(l,mid,node*2);build(mid+1,r,node*2+1);
    calculateNode(node);
}

inline void update(int l=1,int r=n,int node=1){
    if(r<x || x<l)return;
    if(l==r){
        stl[node]=y+(n-l),str[node]=y+l;
        return;
    }
    update(l,mid,node*2);update(mid+1,r,node*2+1);
    calculateNode(node);
}

inline int queryl(int l=1,int r=n,int node=1){
    if(x<l)return INF;
    if(r<=x)return stl[node];
    return min(queryl(l,mid,node*2),queryl(mid+1,r,node*2+1));
}

inline int queryr(int l=1,int r=n,int node=1){
    if(r<x)return INF;
    if(x<=l)return str[node];
    return min(queryr(l,mid,node*2),queryr(mid+1,r,node*2+1));
}

inline void solve(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    build();
    //cerr<<"stl: ";for(int i=1;i<=13;i++)cerr<<stl[i]<<spc;cerr<<endl;
    //cerr<<"str: ";for(int i=1;i<=13;i++)cerr<<str[i]<<spc;cerr<<endl;
    //cerr<<"build ok"<<endl;
    while(q--){
        cin>>x;
        if(x==1){//update
            cin>>x>>y;
            update();
            //cerr<<"stl: ";for(int i=1;i<=13;i++)cerr<<stl[i]<<spc;cerr<<endl;
            //cerr<<"str: ";for(int i=1;i<=13;i++)cerr<<str[i]<<spc;cerr<<endl;
            //cerr<<"update ok"<<endl;
        }
        else{//query
            cin>>x;
            cout<<min(queryl()-n+x,queryr()-x)<<endl;
            //cerr<<"query ok"<<endl;
        }
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
