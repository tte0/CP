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
#define fileio freopen("out.txt","w",stdout);freopen("in.txt","r",stdin)
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
typedef map<int,str> mis;
typedef map<char,int> mci;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<char> stc; 
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
/////////////////////////////////////////////////////////////
int n,m,a,b,k,l,x,y,w,t,fa[N];

inline int dsu(int x){
    return fa[x]==x?x:fa[x]=dsu(fa[x]);
}

inline void merge(int x,int y){
    fa[dsu(x)]=dsu(y);
}

inline int rand_range(int l,int r){
    ll rnd=(RAND_MAX*ll(rand()))+rand();
    return rnd%(r-l+1)+l;
}

int32_t main(void){
    srand(time(NULL));
    freopen("in.txt","w",stdout);
    int n=1e5,m=1e5;
    cout<<n<<spc<<m<<endl;
    /*for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=n;i++)cout<<rand_range(0,1)<<spc;
    for(int i=1;i<m;++i){
        int a=rand_range(1,n)-1,b=rand_range(1,n)-1;
        while(dsu(a)==dsu(b)){a=rand_range(1,n)-1,b=rand_range(1,n)-1;}
        cout<<a<<spc<<b<<endl;
        merge(a,b);
    }*/

    for(int i=0;i<n;i++)cout<<i%2<<spc;
    for(int i=1;i<n;i++)cout<<i-1<<spc<<i<<endl;
    return 0;
}
