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


int32_t main(void){
    fastio;
    cin>>n;
    sti st;
    for(int i=0;i<n;i++){
        cin>>x;
        st.insert(x);
    }
    for(auto i:st)v.pb(i);
    n=v.size();
    int mn=v[0];
    for(int i=0;i+4<n;i++){
        mn=min(mn,v[i+4]-v[i]);
    }
    int maxl=min(v[0]/4,mn);
    for(int l=1;l<=maxl;l++){
        bool ok=true;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt%l==v[i]%l || (cnt/l)%l==v[i]%l || (cnt/(l*l))%l==v[i]%l)continue;
            else{
                cnt*=l;
                cnt+=v[i]%l;
            }
            if(cnt>l*l*l){
                ok=false;
                break;
            }
        }
        if(ok)ans+=l;
    }
    cout<<ans;
}
