/*
MIT License with Attribution and Non-Commercial Use Restriction

Copyright (c) 2024 tte0 (aka. teomana,teoata17)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

1. The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

2. If you use this Software, you must give appropriate attribution by
prominently displaying the original author's name.

3. If you modify the Software, you must clearly indicate that you have
modified the Software and include the original author's name.

4. This Software may not be used for commercial purposes, including, but
not limited to, selling the Software or using the Software in a way that generates income.

THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT
OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma GCC optimize("O3,fast-math")
#include <bits/stdc++.h>
#define int int_fast64_t
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define N (200005)
#define MOD (int(1e9)+7)
#define MOD2 (998244353)
#define MODL (int(1e9)+21)
#define INF (int(4e18))
#define e2(x) (1LL<<(x))
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x*y)/gcd(x,y))
#define smrt(i) (double(sqrt(8*(i)+1)-1)/2)
#define ssum(x) ((x)*((x)+1)/2)
#define isint(x) (ceil((x))==floor((x)))
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define cendl cout<<endl
#define mset(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define dbg(x) cdebug()<<debug(x)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
using namespace std;
typedef long long ll;
typedef long double ldouble;
typedef string str;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
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
/////////////////////////////////////////////////////////////
int n,m,k,t,q,x,y,ans,sum[4*N],sub[4*N],leftt[4*N],rightt[4*N];
vi v={0};
#define m (l+r)/2

inline void merge(int node,int l,int r){
    sum[node]=sum[2*node]+sum[2*node+1];
    leftt[node]=max(leftt[2*node],sum[2*node]+leftt[2*node+1]);
    rightt[node]=max(rightt[2*node+1],sum[2*node+1]+rightt[2*node]);
    sub[node]=max({sub[2*node],sub[2*node+1],rightt[2*node]+leftt[2*node+1]});
}

inline void build(int node=1,int l=1,int r=n){
    if(l==r){
        sum[node]=v[l],
        sub[node]=max(int(0),v[l]);
        leftt[node]=max(int(0),v[l]);
        rightt[node]=max(int(0),v[l]);
        return;
    }
    build(2*node,l,m);
    build(2*node+1,m+1,r);
    merge(node,l,r);
}

inline void query(int node=1,int l=1,int r=n){
    if(r<x || x<l)return;
    //cerr<<">query: "<<node<<","<<l<<","<<r<<endl;
    if(l==r){
        if(l!=x)cout<<"PATLADIN!!"<<endl;
        sum[node]=v[l],
        sub[node]=max(int(0),v[l]);
        leftt[node]=max(int(0),v[l]);
        rightt[node]=max(int(0),v[l]);
        return;
    }
    query(2*node,l,m);
    query(2*node+1,m+1,r);
    merge(node,l,r);
}

inline void debug(){
    cerr<<endl;
    cerr<<"sum: ";for(int i=1;i<16;i++)cerr<<sum[i]<<",";cerr<<endl;
    cerr<<"sub: ";for(int i=1;i<16;i++)cerr<<sub[i]<<",";cerr<<endl;
    cerr<<"left: ";for(int i=1;i<16;i++)cerr<<leftt[i]<<",";cerr<<endl;
    cerr<<"right: ";for(int i=1;i<16;i++)cerr<<rightt[i]<<",";cerr<<endl;
    cerr<<endl;
}

int32_t main(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    build();
    //debug();

    while(q--){
        cin>>x>>y;
        v[x]=y;
        query();
        cout<<sub[1]<<endl;
        //debug();
    }
}
