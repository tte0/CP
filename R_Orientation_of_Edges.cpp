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
#define mp make_pair
#define N (300005)
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
int n,m,start;
vector<iii> v[N],v2[N];
int ans[N],vis[N];
bool type;
map<ii,int> check;

int dfs(int ind)
{
    if(vis[ind])
        return 0;
    vis[ind]=1;
    int cnt=1;
    for(int i=0;i<v[ind].size();i++)
    {
        //if(ind==1)
        //    cout<<v[ind][i].ff<<"a\n ";
        if(v[ind][i].ss.ff==2)
        {
            //cout<<"A "<<ind<<" "<<v[ind][i].ff<<" "<<v[ind][i].ss.ss<<endl;
            if(type)
            {
                ans[v[ind][i].ss.ss]=1;
                v[ind][i].ss.ff=1;
            }
            else
            {
                check[mp(v[ind][i].ff,ind)]=1;
                cnt+=dfs(v[ind][i].ff);
            }
        }
        else if(v[ind][i].ss.ff==3&&!check[mp(ind,v[ind][i].ff)])
        {
            //cout<<ind<<" "<<v[ind][i].ff<<" "<<check[mp(ind,v[ind][i].ff)]<<endl;
            ans[v[ind][i].ss.ss]=1;
            v[ind][i].ss.ff=1;
            cnt+=dfs(v[ind][i].ff);
        }
        else
            cnt+=dfs(v[ind][i].ff);
    }
    return cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>start;
    start--;
    int x=0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        b--;
        c--;
        v[b].pb(mp(c,mp(a,x)));
        v2[b].pb(mp(c,mp(a,x)));
        if(a==2) v2[c].pb(mp(b,mp(a+1,x)));
        x+=(a==2);
    }
    type=true;
    int ans1=dfs(start);
    vector<char> vans;
    for(int i=0;i<x;i++)
    {
        if(ans[i])
            vans.pb('-');
        else
            vans.pb('+');
        //cout<<ans[i]<<" ";
    }
    for(int i=0;i<300002;i++)
    {
        v[i].clear();
        v[i]=v2[i];
    }
    //cout<<"PHASE 2\n";
    type=false;
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    cout<<dfs(start)<<endl;
    for(int i=0;i<x;i++)
    {
        if(ans[i])
            cout<<"-";
        else
            cout<<"+";
        //cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<ans1<<endl;
    for(int i=0;i<x;i++)
    {
        cout<<vans[i];
    }
    return 0;
}

			 	   	 				   	 	       	