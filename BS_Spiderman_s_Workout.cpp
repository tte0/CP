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
int n,m,k,t,q,x,y,ans,dp[50][1005],bt[50][1005];
vi v;

inline int f(int ind,int h){
    if(h<0)return INF;
    if(ind==n){
        if(h==0)return 0;
        return INF;
    }
    if(dp[ind][h]!=-1)return dp[ind][h];
    int t1=f(ind+1,h+v[ind]);
    int t2=max(h,f(ind+1,h-v[ind]));
    if(min(t1,t2)>=INF-10000000){bt[ind][h]=INF;return dp[ind][h]=INF;}
    if(t1<=t2){
        bt[ind][h]=1;
        return dp[ind][h]=t1;
    }
    bt[ind][h]=2;
    return dp[ind][h]=t2;

}

inline void solve(void){
    cin>>n;
    v.clear();
    mset(dp,-1);
    mset(bt,-1);
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    if(f(0,0)>=INF-100000000){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int h=0;
    for(int i=0;i<n;i++){
        if(bt[i][h]==1){
            h+=v[i];
            cout<<"U";
        }
        else if(bt[i][h]==2){
            h-=v[i];
            cout<<"D";
        }
        else{
            cout<<endl<<"PATLADIN OGLUM";
            exit(0);
        }
    }
    cendl;
}

int32_t main(void){
    cin>>t;
    while(t--)solve();
}
