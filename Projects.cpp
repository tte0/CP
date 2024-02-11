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
int n,m,k,t,q,x,y,z,start[2*N],endd[2*N],value[2*N],ans,dp[2*N];
vi v;
viii days;

int32_t main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>z;
        v.pb(x);
        v.pb(y);
        days.pb({x,{y,z}});
    }
    sort(all(days));
    for(int i=0;i<n;i++){
        start[i]=days[i].ff;
        endd[i]=days[i].ss.ff;
        value[i]=days[i].ss.ss;
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(int i=0;i<n;i++){
        start[i]=(lower_bound(all(v),start[i])-v.begin())+1;
        endd[i]=(lower_bound(all(v),endd[i])-v.begin())+1;
    }
    //cerr<<"start: ";for(int i=0;i<n;i++)cerr<<start[i]<<" ";cerr<<endl;
    //cerr<<"end: ";for(int i=0;i<n;i++)cerr<<endd[i]<<" ";cerr<<endl<<endl<<endl;
    int mx=0,ind=0;
    for(int i=0;i<n;i++){
        for(;ind<start[i];ind++)mx=max(mx,dp[ind]);
        dp[endd[i]]=max(dp[endd[i]],mx+value[i]);
    }
    for(int i=0;i<=2*n;i++)ans=max(ans,dp[i]);
    cout<<ans;
}
