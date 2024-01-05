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
int_fast32_t n,m,k,t,q,x,y,ans,itoc[N],ctoi[N],vis[N],query[N];
int_fast32_t sparse[2*N][20];
vi adj[N],traversal;


inline dfs(int node,int p){
    traversal.pb(itoc[node]);
    for(int i:adj[node]){
        dfs(i,node);
        traversal.pb(itoc[node]);
    }
}

int32_t main(void){
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    queue<ii> q;
    int cnt=1;
    q.push(ii(1,0));
    while(!q.empty()){
        int node=q.front().ff,depth=q.front().ss;q.pop();
        if(vis[node]++)continue;
        itoc[node]=cnt;
        ctoi[cnt++]=node;
        for(int i:adj[node])q.push({i,depth});
    }
    dfs(1,-1);
    int tsize=traversal.size();
    for(int i=0;i<tsize;i++){
        query[traversal[i]]=i;
    }

    for(int i=0;i<tsize;i++){
        sparse[i][0]=traversal[i];
    }
    for(int j=1;j<20;j++){
        for(int i=0;i<tsize;i++){
            sparse[i][j]=sparse[i][j-1];
            if(i+e2(j-1)<tsize)sparse[i][j]=min(sparse[i][j],sparse[i+e2(j-1)][j-1]);
        }
    }
    while(m--){
        cin>>x>>y;
        x=query[itoc[x]];
        y=query[itoc[y]];
        if(x>y)swap(x,y);
        int dist=__lg(y-x);
        cout<<ctoi[min(sparse[x][dist],sparse[y-e2(dist)][dist])]<<" ";
    }
}
