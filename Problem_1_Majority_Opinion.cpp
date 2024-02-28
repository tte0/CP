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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef map<int,int> mii;
int n,m,k,t,q,x,y,ans;
vi v;

inline void solve(void){
    cin>>n;
    vi v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    mii mp;
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1])mp[v[i]]++;
    }
    for(int i=0;i<n-2;i++){
        if(v[i]==v[i+2])mp[v[i]]++;
    }
    if(mp.size()==0){
        cout<<-1<<endl;
        return;
    }
    for(auto i:mp){
        if(*(mp.begin())!=i)cout<<" ";
        cout<<i.ff;
    }
    cendl;
    return;
}

int32_t main(void){
    cin>>t;
    while(t--)solve();
}
