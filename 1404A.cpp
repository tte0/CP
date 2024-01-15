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
str s;
inline void solve(void){
    cin>>n>>k>>s;
    for(int i=0;i<k;i++){
        int cnt=0,cnt1=0,cnt2=0;
        for(int j=i;j<n;j+=k){
            if(s[j]=='0')cnt++;
            if(s[j]=='1')cnt1++;
            if(s[j]=='?')cnt2++;
        }
        if(min(cnt,cnt1)>0){
            no;
            return;
        }
        if(cnt)for(int j=i;j<n;j+=k)s[j]='0';
        if(cnt1)for(int j=i;j<n;j+=k)s[j]='1';
    }
    int cnt=0,cnt1=0;
    for(int i=0;i<k;i++){
        if(s[i]=='0')cnt++;
        if(s[i]=='1')cnt1++;
    }
    if(cnt>k/2 || cnt1>k/2){
        no;
        return;
    }
    for(int i=0;i+k<n;i++){
        if(s[i]=='0')cnt--;
        if(s[i]=='1')cnt1--;
        if(s[i+k]=='0')cnt++;
        if(s[i+k]=='1')cnt1++;
        if(cnt>k/2 || cnt1>k/2){
            no;
            return;
        }
    }
    yes;
}

int32_t main(void){
    cin>>t;
    while(t--)solve();
}
