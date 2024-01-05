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
int n,m,k,t,q,x,y,ans;
vi v;

bool f(vi& a,vi& b){
    vi prefixa,prefixb;
    prefixa.pb(a[0]);
    prefixb.pb(b[0]);
    for(int i=1;i<a.size();i++)prefixa.pb(prefixa.back()+a[i]);
    for(int i=1;i<b.size();i++)prefixb.pb(prefixb.back()+b[i]);

    //cerr<<"pa:";for(auto i:prefixa)cerr<<i<<",";cerr<<endl;
    //cerr<<"pb:";for(auto i:prefixb)cerr<<i<<",";cerr<<endl;

    mii mp;mp[0]++;
    for(int i=0;i<b.size();i++)mp[prefixa[i]-prefixb[i]]++;
    for(auto i:mp){
            //cerr<<i.ff<<endl;
        if(i.ss>1){
            return true;
        }
    }
    //cerr<<"ok"<<endl;
    mp.clear();mp[0]++;
    for(int i=0;i<a.size()-1;i++){
        if(mp[a[i+1]+prefixa[i]-prefixb[i]]){
            //cerr<<i<<","<<a[i+1]+prefixa[i]-prefixb[i]<<endl;
            return true;
        }
        mp[prefixa[i]-prefixb[i]]++;
    }
    //cerr<<"ok";
    return false;
}

inline void solve(void){
    cin>>n;
    vi a,b;
    for(int i=0;i<n;i++){
        cin>>x;
        if(i&1)b.pb(x);
        else a.pb(x);
    }
    if(n==1){
        no;
        return;
    }
    
    if(f(a,b)){
        yes;
        return;
    }
    a.erase(a.begin());
    a.swap(b);
    if(f(a,b)){
        yes;
        return;
    }
    no;
}

int32_t main(void){
    cin>>t;
    while(t--)solve();

}
