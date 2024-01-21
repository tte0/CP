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
int n=8;
int base=57,mod=e2(32);
str a,b;
mis mp;

int fp(int b,int p,int mod){
    if(p==0)return 1;
    int t=fp(b,p/2,mod);
    t=(t*t)%mod;
    if(p%2)t=(t*b)%mod;
    return t;
}

int32_t main(void){
    srand(time(NULL));
    while(true){
        str s;
        for(int i=0;i<n;i++){
            s.pb(rand()%26+'a');
        }
        int hash=0;
        for(int i=0;i<n;i++){
            hash+=(fp(base,i,mod)*(s[i]-'a'+1))%mod;
            hash=hash%mod;
        }
        if(mp[hash]!="" && mp[hash]!=s){
            a=s;
            b=mp[hash];
            break;
        }
        mp[hash]=s;
    }
    cout<<a<<endl<<b<<endl<<endl;
    reverse(all(a));
    reverse(all(b));
    cout<<a<<endl<<b<<endl<<endl;
}
