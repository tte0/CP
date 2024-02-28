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

inline void solve(void){
    cin>>n>>q>>y>>x;
    mii mp;mp[1]=x;
    vi v(n,0);v[0]=1;
    for(int i=1;i<n;i++){
        cin>>x;
        v[i]=v[i-1];
        if(x==1){
            cin>>x;
            v[i]++;
            if(v[i]+1>INF){
                v[i]=INF;
                continue;
            }
            mp[v[i]]=x;
        }
        else{
            cin>>x;
            if(v[i]>INF/(x+1)){
                v[i]=INF;
                continue;
            }
            v[i]+=v[i]*x;
        }
    }
    //cerr<<"preprocess ok"<<endl;
    //cerr<<"v: ";for(auto i:v)cerr<<i<<",";cerr<<endl;
    while(q--){
        cin>>x;
        while(x>1){
            //cerr<<"x: "<<x<<endl;
            if(mp[x]!=0)break;
            //cerr<<"a";
            auto it=lower_bound(v.begin(),v.end(),x);
            //cerr<<"b";
            it--;
            //cerr<<"c";
            x=((x-1)%*it)+1;
            //cerr<<" "<<x<<endl;
        }
        //cerr<<"binary ok"<<endl;
        cout<<mp[x]<<" ";
        //cerr<<"query: "<<q<<" ok"<<endl;
    }
    cendl;
}

int32_t main(void){
    fastio;
    cin>>t;
    while(t--){
        solve();
        //cerr<<"solve ok"<<endl;
    }
}
