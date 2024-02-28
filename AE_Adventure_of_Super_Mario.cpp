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
#define int ll
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
typedef pair<ii,ii> iiii;
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
int a,b,n,m,k,l,bigl,t,q,x,y,w,ans;
vi v;
vii adj[N];

inline void solve(void){
    cin>>a>>b>>m>>l>>k;
    n=a+b;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    priority_queue<iiii, vector<iiii>, greater<iiii>> q;//dist,node,k,lnn
    int vis[n+5][k+5][l+5];
    mset(vis,-1);
    q.push({{0,n},{k,0}});
    while(q.size()){
        int d=q.top().ff.ff;
        int node=q.top().ff.ss;
        int k=q.top().ss.ff;
        int curl=q.top().ss.ss;
        q.pop();
        //if(node==3 && d==17 && k==2 && curl==34)cerr<<"GELDI4: ";
        //if(node==5 && d==17 && k==2 && curl==41)cerr<<"GELDI14: ";
        //cerr<<"node,d,k,curl : "<<node<<" "<<d<<" "<<k<<" "<<l<<endl;
        if(vis[node][k][curl]!=-1){continue;}
        vis[node][k][curl]=d;
        if(node==1){
            cout<<d<<endl;
            return;
        }
        for(auto i:adj[node]){
            int y=i.ff,w=i.ss;
            q.push({{w+d,y},{k,0}});
            if(y<=a){
                if(curl==0){
                    if(w<=l && k)q.push({{d,y},{k-1,w}});
                }
                else if(w+curl<=l)q.push({{d,y},{k,w+curl}});
                else if(w<=l && k)q.push({{d,y},{k-1,w}});
            }
            else{
                if(curl==0){
                    if(w<=l && k)q.push({{d,y},{k-1,0}});
                }
                else if(w+curl<=l)q.push({{d,y},{k,0}});
                //else if(w+curl==l&&k)q.push({{d,y},{k-1,0}});
                else if(w<=l && k)q.push({{d,y},{k-1,0}});
            }
        }
    }
    
    cout<<100000000<<endl;
}

int32_t main(void){
    cin>>t;
    while(t--)solve();
}
