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
int n,x,y,color[N],mpindex[N],sz[N],mpindexcnt,sum[N];
vi adj[N];
mii mp[32];
stii st[32];

inline void dfs1(int node,int p){
    sz[node]=1;
    if(!adj[node].size() || (adj[node].size()==1 && node!=1)){
        mpindex[node]=++mpindexcnt;
        return;
    }
    int mx=0;
    for(auto i:adj[node]){
        if(i==p)continue;
        dfs1(i,node);
        sz[node]+=sz[i];
        if(sz[i]>sz[mx])mx=i;
    }
    mpindex[node]=mpindex[mx];
    return;
}

inline void mrg(int base,int added){

    for(auto i:mp[added]){
        int x=i.ff,cnt=i.ss;
        if(mp[base][x]!=0)st[base].erase(st[base].find({mp[base][x],x}));
        mp[base][x]+=cnt;
        st[base].insert({mp[base][x],x});
    }
    return;
}

inline void dfs2(int node,int p){
    //cerr<<">>dfs2 = "<<node<<endl;
    if(!adj[node].size() || (adj[node].size()==1 && node!=1)){
        mp[mpindex[node]][color[node]]=-1;
        st[mpindex[node]].insert({mp[mpindex[node]][color[node]],color[node]});
        sum[node]=color[node];
        //cerr<<"leaf ok"<<endl;
        return;
    }
    for(auto i:adj[node]){
        if(i==p)continue;
        dfs2(i,node);
        if(mpindex[i]==mpindex[node])continue;
        //cerr<<">>mrg = "<<node<<","<<i<<endl;
        mrg(mpindex[node],mpindex[i]);
        //cerr<<"merge ok"<<endl;
    }

    mp[31].clear();st[31].clear();
    mp[31][color[node]]=-1;
    st[31].insert({-1,color[node]});
    mrg(mpindex[node],31);

    auto it=st[mpindex[node]].begin();
    while(it!=st[mpindex[node]].end() && (*it).ff==(*st[mpindex[node]].begin()).ff){
        sum[node]+=(*it).ss;
        it++;
    }
    return;
}

int32_t main(void){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>color[i];
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(1,-1);
    cout<<mpindexcnt;
    //cerr<<"sz: ";for(int i=1;i<=n;i++)cerr<<sz[i]<<",";cerr<<endl;
    //cerr<<"mpindex: ";for(int i=1;i<=n;i++)cerr<<mpindex[i]<<",";cerr<<endl;

    dfs2(1,-1);
    //cerr<<endl<<"dfs2 ok"<<endl<<endl;
    for(int i=1;i<=n;i++)cout<<sum[i]<<" ";
    //cerr<<endl<<"output ok"<<endl<<endl;
}
