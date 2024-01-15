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

ii longestPalindrome(vi& s){
    for(int i:s)cerr<<i;cerr<<endl;
    int n=s.size();
    int manacher[2*n+5];
    mset(manacher,0);
    vi con={-10};
    for(int i=0;i<n;i++){
        con.pb(-1);
        con.pb(s[i]);
    }
    con.pb(-1);
    con.pb(-20);
    n=con.size();
    int l=0,center=0,r=0,lenght=0;
    for(int i=1;i<n-1;i++){
        if(i<r)manacher[i]=min(r-i,manacher[2*center-i]);
        while(con[i-manacher[i]-1]==con[i+manacher[i]+1])manacher[i]++;
        if(i+manacher[i]>r){
            center=i;
            r=i+manacher[i];
        }
        if(manacher[i]>lenght){
            l=i-manacher[i];
            lenght=manacher[i];
        }
    }
    return {l/2,(l+2*lenght)/2-1};
    for(int i=l;i<=l+2*lenght;i++){
        if(con[i]!=-1)cout<<con[i];
    }
}


int32_t main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    while(v.size()){
        ii cnt=longestPalindrome(v);
        vi v2;
        for(int i=0;i<v.size();i++){
            if(!(cnt.ff<=i && i<=cnt.ss))v2.pb(v[i]);
        }
        v=v2;
        ans++;
    }
    cout<<ans<<endl;
}
