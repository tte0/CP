#pragma GCC optimize("O1,O2,O3,O4,Ofast,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#include <bits/stdc++.h>
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
int n,m,k,t,q,x,y,ans=1;
vi v;
int place[N];

int32_t main(void){
    fastio;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        place[x]=i;
        v.pb(x);
    }
    for(int i=1;i<n;i++){
        ans+=(place[i]>place[i+1]);
    }
    while(m--){
        
        int xplace,yplace;
        cin>>xplace>>yplace;
        xplace--;
        yplace--;
        x=v[xplace];
        y=v[yplace];
        if(x>y){
            swap(x,y);//placeler swaplı değil!!
        }
        if(x!=1){
            if(place[x-1]>place[x])ans--;
            if(place[x-1]>place[y])ans++;
        }
        if(y!=n){
            if(place[y]>place[y+1])ans--;
            if(place[x]>place[y+1])ans++;
        }
        if(y-x>1){
            if(place[y-1]>place[y])ans--;
            if(place[y-1]>place[x])ans++;

            if(place[x]>place[x+1])ans--;
            if(place[y]>place[x+1])ans++;
        }
        else{
            if(place[x]>place[y])ans--;
            if(place[y]>place[x])ans++;
        }
        swap(v[yplace],v[xplace]);
        swap(place[y],place[x]);
        cout<<ans<<endl;
    }
}   
