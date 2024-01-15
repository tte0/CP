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
/////////////////////////////////////////////////////////////,
int n,m,k,t,q,x,y,dp[N][2];
vi adj[N];

inline int f(int node,int x,int p){
    if(dp[node][x]!=-1)return dp[node][x];
    if(adj[node].size()==1 and adj[node][0]==p)return dp[node][x]=0;
    int ans=0;
    int sum=0;
    for(int i:adj[node]){
        if(i!=p)
        sum+=f(i,1,node);
    }
    ans=sum;
    //cerr<<"node,x: "<<node<<" "<<x<<" = "<<sum<<endl;
    if(x==0)return dp[node][x]=ans;
    for(auto i:adj[node]){
        if(i==p)continue;
        int t=dp[i][1];
        sum-=t;
        int t2=f(i,0,node);
        sum+=t2;
        ans=max(ans,sum+1);
        //cerr<<"node,x,i: "<<node<<" "<<x<<" "<<i<<" = "<<ans<<endl;
        sum-=t2;
        sum+=t;
    }
    return dp[node][x]=ans;
}


int32_t main(void){
    cin>>n;mset(dp,-1);
    for(int i=2;i<=n;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cout<<f(1,1,-1);
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            cerr<<dp[i][j]<<" ";
        }
        cerr<<endl;
    }*/
}

