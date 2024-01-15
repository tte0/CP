#pragma GCC optimize("O3,fast-math")
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
int n,m,k,t,q,x,y,ans=MOD,arr[1005][1005],dp[1005][1005];
char bt[1005][1005];
str s;

int twoValue(int x){
    if(!x)return 1;
    int cnt=0;
    while(x%2==0){
        cnt++;
        x/=2;
    }
    return cnt;
}
int fiveValue(int x){
    if(!x)return 1;
    int cnt=0;
    while(x%5==0){
        cnt++;
        x/=5;
    }
    return cnt;
}

int32_t main(void){
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>arr[i][j];

    //two value
    dp[0][0]=twoValue(arr[0][0]);
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+twoValue(arr[i][0]);
        bt[i][0]='D';
    }
    for(int j=1;j<n;j++){
        dp[0][j]=dp[0][j-1]+twoValue(arr[0][j]);
        bt[0][j]='R';
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(dp[i-1][j]<dp[i][j-1]){
                dp[i][j]=dp[i-1][j]+twoValue(arr[i][j]);
                bt[i][j]='D';
            }
            else{
                dp[i][j]=dp[i][j-1]+twoValue(arr[i][j]);
                bt[i][j]='R';
            }
        }
    }
    ans=dp[n-1][n-1];
    x=n-1,y=n-1;
    while(x || y){
        s.pb(bt[x][y]);
        if(bt[x][y]=='D')x--;
        else y--;
    }
    //debug
    /*cerr<<"ans: "<<ans<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cerr<<bt[i][j];
        cerr<<endl;
    }*/
    //five value
    dp[0][0]=fiveValue(arr[0][0]);
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+fiveValue(arr[i][0]);
        bt[i][0]='D';
    }
    for(int j=1;j<n;j++){
        dp[0][j]=dp[0][j-1]+fiveValue(arr[0][j]);
        bt[0][j]='R';
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(dp[i-1][j]<dp[i][j-1]){
                dp[i][j]=dp[i-1][j]+fiveValue(arr[i][j]);
                bt[i][j]='D';
            }
            else{
                dp[i][j]=dp[i][j-1]+fiveValue(arr[i][j]);
                bt[i][j]='R';
            }
        }
    }
    if(ans>dp[n-1][n-1]){
        ans=dp[n-1][n-1];
        s.clear();
        x=n-1,y=n-1;
        while(x || y){
            s.pb(bt[x][y]);
            if(bt[x][y]=='D')x--;
            else y--;
        }
    }
    //debug
    /*cerr<<"ans: "<<ans<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cerr<<bt[i][j];
        cerr<<endl;
    }*/
    ///
    int flag=0;
    reverse(all(s));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(arr[i][j]==0){flag=1;x=i,y=j;}
    if(flag && ans){
        ans=1;
        s.clear();
        for(int i=0;i<x;i++)s.pb('D');
        for(int i=0;i<n-1;i++)s.pb('R');
        for(int i=x;i<n-1;i++)s.pb('D');
    }
    cout<<ans<<endl<<s;
}
