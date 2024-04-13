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
const int N=100;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n=8,m,k,t,q,a,b,x,y,w,ans;
int adj[N][N];
vi v;

inline void solve(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-1>=0 && j-2>=0)adj[8*i+j][8*(i-1)+(j-2)]=1;
            if(i-2>=0 && j-1>=0)adj[8*i+j][8*(i-2)+(j-1)]=1;
            if(i+1<n && j-2>=0)adj[8*i+j][8*(i+1)+(j-2)]=1;
            if(i+2<n && j-1>=0)adj[8*i+j][8*(i+2)+(j-1)]=1;
            if(i-1>=0 && j+2<n)adj[8*i+j][8*(i-1)+(j+2)]=1;
            if(i-2>=0 && j+1<n)adj[8*i+j][8*(i-2)+(j+1)]=1;
            if(i+1<n && j+2<n)adj[8*i+j][8*(i+1)+(j+2)]=1;
            if(i+2<n && j+1<n)adj[8*i+j][8*(i+2)+(j+1)]=1;
        }
    }
    cerr<<"adj ok"<<endl;
    cin>>x>>y;
    x--,y--;
    x=x+8*y;
    v.pb(x);
    for(int round=0;round<63;round++){
        cerr<<"round "<<round<<" ok| x="<<x<<endl;
        if(x==-1){
            for(int i=0;i<64;i++){
                if(i%8==0)cerr<<endl;
                int ok=0;
                for(int j=0;j<64;j++)ok|=adj[i][j];
                cerr<<ok<<" ";
            }
            cerr<<endl;
        }

        int y=-1,mx=-1;
        for(int i=0;i<64;i++){
            if(adj[x][i]){
                int cnt=0;
                for(int j=0;j<64;j++)cnt+=adj[i][j];
                if(cnt>mx){
                    mx=cnt;
                    y=i;
                }
            }
        }
        v.pb(y);
        for(int i=0;i<64;i++)adj[x][i]=0,adj[i][x]=0;
        x=y;
    }
    int arr[8][8];
    for(int i=0;i<64;i++)arr[i/8][i%8]=v[i];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)cout<<arr[i][j]+1<<spc;
        cout<<endl;
    }
}

int32_t main(void){
    fastio;
    t=1;
    //cin>>t;
    while(t--)solve();
}
