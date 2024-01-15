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
ldouble cnt[8][8][105],dp[8][8];
vi v;


int32_t main(void){
    cout<<fixed<<setprecision(6);
    cerr<<fixed<<setprecision(6);
    cin>>n;
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)cnt[i][j][0]=dp[i][j]=1;

    for(int t=0;t<n-1;t++){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                int x=4;
                if(i==0 || i==7)x--;
                if(j==0 || j==7)x--;

                if(i>0)cnt[i-1][j][t+1]+=cnt[i][j][t]/x;
                if(i<7)cnt[i+1][j][t+1]+=cnt[i][j][t]/x;
                if(j>0)cnt[i][j-1][t+1]+=cnt[i][j][t]/x;
                if(j<7)cnt[i][j+1][t+1]+=cnt[i][j][t]/x;
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)cerr<<cnt[i][j][1]<<",";
        cerr<<endl;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int x=4;
            if(i==0 || i==7)x--;
            if(j==0 || j==7)x--;

            if(i>0)dp[i-1][j]*=powl(float(x-1)/x,cnt[i][j][n-1]);
            if(i<7)dp[i+1][j]*=powl(float(x-1)/x,cnt[i][j][n-1]);
            if(j>0)dp[i][j-1]*=powl(float(x-1)/x,cnt[i][j][n-1]);
            if(j<7)dp[i][j+1]*=powl(float(x-1)/x,cnt[i][j][n-1]);
        }
    }
    ldouble ans;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ans+=dp[i][j];
        }
    }

    cout<<floor(ans*1000000)/1000000;
}
