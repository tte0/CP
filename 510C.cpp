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
int n,m,k,t,q,x,y,vis[26],cnt[26];
str s[105];
vi adj[30];
string ans;

inline bool dfs(int node){
    ans.pb(node+'a');
    if(vis[node]++)return false;
    for(auto i:adj[node])dfs(i);
}

int32_t main(void){
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n-1;i++){
        str x=s[i],y=s[i+1];
        x.pb('!');
        y.pb('!');
        int ind=0;
        while(x[ind]==y[ind])ind++;
        if(y[ind]=='!'){
            cout<<"Impossible"<<endl;
            cerr<<"yarida"<<endl;
            return 0;
        }
        if(x[ind]!='!'){adj[x[ind]-'a'].pb(y[ind]-'a');cnt[y[ind]-'a']++;}
        cerr<<"i="<<i<<" ok"<<endl;
    }
    for(int i=0;i<26;i++){
        if(vis[i]==0 && cnt[i]==0)dfs(i);
    }
    if(ans.size()>26)cout<<"Impossible";
    cout<<ans<<endl;
}
