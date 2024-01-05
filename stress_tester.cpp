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
///////////////////////////////////////////////////////////// sum: a[l]*a[r]*(r-l-1)
int n,m,k,t,x,y,ans;
vi v;
mii mp;

int solve(int n,vi v){
    sort(all(v));
    int ans=0;
    int prefv[n+5],prefp[n+5],p[n+5];
    mset(prefp,0);
    mset(prefv,0);
    mset(p,0);
    for(int i=1;i<=n;i++)prefv[i]=prefv[i-1]+v[i-1];
    for(int i=0;i<n;i++) p[i]=(i+1)*v[i];
    for(int i=1;i<=n;i++)prefp[i]=prefp[i-1]+p[i-1];
    
    /*cerr<<"p: ";for(int i=0;i<n;i++)cerr<<p[i]<<",";cerr<<endl;
    cerr<<"p: ";for(int i=1;i<=n;i++)cerr<<prefp[i]<<",";cerr<<endl;*/

    for(int i=0;i<n-1;i++){
        ans+=v[i]*(prefp[n]-prefp[i+1]);
        ans=(ans+(MOD-7))%(MOD-7);
    }
    //cerr<<ans<<endl;
    for(int i=0;i<n-1;i++){
        ans-=p[i]*(prefv[n]-prefv[i+1]);
        ans=(ans+(MOD-7))%(MOD-7);
    }
    //cerr<<ans<<endl;
    /*for(int i=0;i<n-1;i++){
        ans-=v[i]*v[i+1];
        ans=(ans+(MOD-7))%(MOD-7);
    }*/
    for(int i=0;i<n-1;i++){
        ans-=v[i]*(prefv[n]-prefv[i+1]);
        ans=(ans%(MOD-7)+(MOD-7))%(MOD-7);
    }
    
    return ans;
}

int solution(int n,vi v){
    sort(all(v));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans+=v[i]*v[j]*(j-i-1);
            ans=(ans%(MOD-7)+(MOD-7))%(MOD-7);
        }
    }
    return ans;
}

int32_t main(void){
    srand(time(NULL));
    cin>>n>>x;
    while(1){
        vi v;
        for(int i=0;i<n;i++){
            v.pb(rand()%(x+2)-1);
        }
        int judge=solution(n,v);
        int answer=solve(n,v);
        if(answer!=judge){
            cout<<"Wrong Answer on input:"<<endl<<n<<endl;
            for(auto i:v)cout<<i<<" ";
            cout<<endl<<"Judger: "<<judge<<endl<<"Answer: "<<answer<<endl;
            return 0;
        }
    }
}

