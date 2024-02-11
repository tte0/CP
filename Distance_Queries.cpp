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
#define lg(x) (__lg(x))
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
int n,m,k,t,q,x,y,ans,depth[N],value[N],id[N],place[2*N],sparse[2*N][19];
vi adj[N],travel;
 
inline void dfs(int node,int p){
    //cerr<<">>DFS: node,p : "<<node<<","<<p<<endl;
    travel.pb(value[node]);
    for(int i:adj[node]){
        if(i==p)continue;
        dfs(i,node);
        travel.pb(value[node]);
    }
}
 
inline void calculateSparse(){
    int n=travel.size();
    for(int i=0;i<n;i++)place[travel[i]]=i;
 
    for(int i=0;i<n;i++)sparse[i][0]=travel[i];
    for(int j=1;j<=lg(n);j++){
        for(int i=0;i<n;i++){
            sparse[i][j]=sparse[i][j-1];
            if(i+e2(j-1)<n)sparse[i][j]=min(sparse[i][j],sparse[i+e2(j-1)][j-1]);
        }
    }
}
 
inline void lca(int x,int y){
    int a=x,b=y;
    x=place[value[x]];
    y=place[value[y]];
    if(x>y)swap(x,y);
    int dist=lg(abs(x-y)+1);
    int ans=sparse[x][dist];
    ans=min(ans,sparse[y-e2(dist)+1][dist]);
    cout<<depth[a]+depth[b]-2*depth[id[ans]]<<endl;
}
 
int32_t main(void){
    fastio;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
 
    mset(depth,-1);
    mset(value,-1);
    mset(id,-1);
    int cnt=1;
    queue<ii> q;
    q.push({1,0});
    while(q.size()){
        int node=q.front().ff,d=q.front().ss;q.pop();
        if(depth[node]!=-1)continue;
        depth[node]=d;
        id[cnt]=node;
        value[node]=cnt++;
        for(int i:adj[node]){
            q.push({i,d+1});
        }
    }
 
    /*cerr<<endl<<"BFS ok"<<endl;
    cerr<<"depth: ";for(int i=1;i<=n;i++)cerr<<depth[i]<<",";cerr<<endl;
    cerr<<"id: ";for(int i=1;i<=n;i++)cerr<<id[i]<<",";cerr<<endl;
    cerr<<"value: ";for(int i=1;i<=n;i++)cerr<<value[i]<<",";cerr<<endl;*/
     
    dfs(1,-1);
 
    /*cerr<<endl<<"DFS ok"<<endl;
    cerr<<"travel: ";for(int i:travel)cerr<<i<<",";cerr<<endl;*/
 
    calculateSparse();
 
    /*cerr<<endl<<"sparse ok"<<endl;
    for(int j=0;j<4;j++){
        cerr<<"sparse:";
        for(int i=0;i<int(travel.size());i++)cerr<<sparse[i][j]<<",";
        cerr<<endl;
    }
    cerr<<"place: ";for(int i=1;i<=n;i++)cerr<<place[i]<<",";cerr<<endl;*/
 
 
    while(m--){
        cin>>x>>y;
        lca(x,y);
    }
}