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
int n,m,k,t,q,x,y,ans[N],vis[N],diameterNode1,diameterNode2;
vi adj[N];

inline void dfs(int node,int p,int depth){
    if(depth>ans[node])ans[node]=depth;
    for(int i:adj[node])if(i!=p)dfs(i,node,depth+1);
}

int32_t main(void){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    queue<int> q;
    q.push(1);
    while(q.size()){
        int node=q.front();q.pop();
        if(vis[node]++)continue;
        for(int i:adj[node])q.push(i);
        diameterNode1=node;
    }
    mset(vis,0);
    q.push(diameterNode1);
    while(q.size()){
        int node=q.front();q.pop();
        if(vis[node]++)continue;
        for(int i:adj[node])q.push(i);
        diameterNode2=node;
    }
    dfs(diameterNode1,-1,0);
    dfs(diameterNode2,-1,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}
