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
/////////////////////////////////////////////////////////////,
int n,m,k,t,x,y,dp[5005][5005];
str s,q;

int32_t main(void){
    cin>>s>>q;
    n=s.size();
    m=q.size();
    dp[0][0]=(s[0]!=q[0]);
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+1;
        if(s[i]==q[0])dp[i][0]=min(dp[i][0],i);
    }
    for(int i=1;i<m;i++){
        dp[0][i]=dp[0][i-1]+1;
        if(s[0]==q[i])dp[0][i]=min(dp[0][i],i);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            if(s[i]==q[j])dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        }
    }/*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cerr<<dp[i][j]<<",";
            if(dp[i][j]<10)cerr<<" ";
        }
        cerr<<endl;
    }*/
    cout<<dp[n-1][m-1];
}

//ugjkvvibvgggozw