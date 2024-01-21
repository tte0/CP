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
#define no cout<<<"NO"<<endl
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
typedef set<ii> stii;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
/////////////////////////////////////////////////////////////
int n,x,y,color[N],cnt[N],ans[N],sz[N];
vi adj[N];
mii mp[N];


inline void mrg(int base,int added){
    for(auto i:mp[added]){
        int x=i.ff;
        mp[base][x]+=i.ss;
        if(mp[base][x]==cnt[base])ans[base]+=x;
        else if(mp[base][x]>cnt[base]){
            cnt[base]=mp[base][x];
            ans[base]=i.ff;
        }
    }
    return;
}

inline void dfs(int node,int p){
    sz[node]=1;
    if(adj[node].size()==0 || (adj[node].size()==1 && node!=1)){
        mp[node][color[node]]++;
        cnt[node]=1;
        ans[node]=color[node];
        return;
    }
    int mx=0;
    for(auto i:adj[node]){
        if(i==p)continue;
        dfs(i,node);
        sz[node]+=sz[i];
        if(sz[mx]<sz[i])mx=i;
    }   
    swap(mp[node],mp[mx]);
    cnt[node]=cnt[mx];ans[node]=ans[mx];
    if(mp[node][color[node]]++==cnt[node]){
        cnt[node]++;
        ans[node]=color[node];
    }
    else if(mp[node][color[node]]==cnt[node]){
        ans[node]+=color[node];
    }

    for(auto i:adj[node]){
        if(i==p || i==mx)continue;
        mrg(node,i);
    } 
}

int32_t main(void){
    sz[0]=-INF;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>color[i];
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    //cerr<<"cnt: ";for(int i=1;i<=n;i++)cerr<<cnt[i]<<",";cerr<<endl;
}
