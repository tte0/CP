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
int n,m,k,t,q,x,y,ans,arr[105][105],vis[105][105];
vi v;

inline void solve(void){
    mset(arr,-1);
    mset(vis,0);
    queue<iii> q;
    int mx,my;
    cin>>mx>>my>>x>>y;
    q.push({0,{x,y}});
    cin>>x>>y;
    q.push({0,{x,y}});
    while(q.size()){
        int d=q.front().ff,x=q.front().ss.ff,y=q.front().ss.ss;q.pop();
        if(x<1 || n<x || y<1 || m<y)continue;
        if(arr[x][y]!=-1)continue;
        arr[x][y]=d;
        q.push({d+1,{x+1,y}});
        q.push({d+1,{x,y+1}});
        q.push({d+1,{x-1,y}});
        q.push({d+1,{x,y-1}});
    }
    q.push({0,{mx,my}});
    while(q.size()){
        int d=q.front().ff,x=q.front().ss.ff,y=q.front().ss.ss;q.pop();
        if(x<1 || n<x || y<1 || m<y){
            yes;
            return;
        }
        if(vis[x][y]++ || arr[x][y]<=d)continue;    
        q.push({d+1,{x+1,y}});
        q.push({d+1,{x,y+1}});
        q.push({d+1,{x-1,y}});
        q.push({d+1,{x,y-1}});
    }
    no;
}

int32_t main(void){
    cin>>n>>m>>t;
    while(t--)solve();

}
