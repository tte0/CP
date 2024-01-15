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
int n,m,k,t,q,x,y,ans,mvis[1005][1005],ax,ay;
int vis[1005][1005];
char bt[1005][1005];//ULRD
str s[1005];

int32_t main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)mvis[i][j]=INF;
    }
    mset(vis,0);
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++)if(s[i][j]=='A')ax=i,ay=j;
    }
    queue<iii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='M')q.push({0,{i,j}});
        }
    }
    while(q.size()){
        int x=q.front().ss.ff,y=q.front().ss.ss,d=q.front().ff;q.pop();
        if(mvis[x][y]!=INF or s[x][y]=='#')continue;
        //cerr<<"x,y,d : "<<x<<","<<y<<","<<d<<endl;
        mvis[x][y]=d;
        if(x>0)q.push({d+1,{x-1,y}});
        if(x<n-1)q.push({d+1,{x+1,y}});
        if(y>0)q.push({d+1,{x,y-1}});
        if(y<m-1)q.push({d+1,{x,y+1}});
    }

    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mvis[i][j]!=-1)//cerr<<" ";
            //cerr<<mvis[i][j]<<",";
        }
        //cerr<<endl;
    }*/

    q.push({0,{ax,ay}});
    while(q.size()){
        int x=q.front().ss.ff,y=q.front().ss.ss,d=q.front().ff;q.pop();
        if(vis[x][y]++ or s[x][y]=='#' or d>=mvis[x][y])continue;
        //cerr<<"x,y,d : "<<x<<","<<y<<","<<d<<endl;
        if(x==0 or x==n-1 or y==0 or y==m-1){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    //cerr<<bt[i][j];
                }
                //cerr<<endl;
            }
            yes;
            str s;
            //cerr<<"ax="<<ax<<" : ay="<<ay<<endl;
            while(x!=ax or y!=ay){
                //cerr<<"x,y : "<<x<<","<<y<<endl;
                s.pb(bt[x][y]);
                if(s.back()=='U')x--;
                else if(s.back()=='D')x++;
                else if(s.back()=='L')y--;
                else if(s.back()=='R')y++;
                //cerr<<"x,y : "<<x<<","<<y<<endl;
            }
            cout<<s.size()<<endl;
            while(s.size()){
                if(s.back()=='U')cout<<'D';
                if(s.back()=='D')cout<<'U';
                if(s.back()=='R')cout<<'L';
                if(s.back()=='L')cout<<'R';
                s.pop_back();
            }
               

            return 0;
        }
        if(x>0){
            if(bt[x-1][y]==0)bt[x-1][y]='D';
            q.push({d+1,{x-1,y}});
        }
        if(y>0){
            if(bt[x][y-1]==0)bt[x][y-1]='R';
            q.push({d+1,{x,y-1}});
        }
        if(x<n-1){
            if(bt[x+1][y]==0)bt[x+1][y]='U';
            q.push({d+1,{x+1,y}});
        }
        if(y<m-1){
            if(bt[x][y+1]==0)bt[x][y+1]='L';
            q.push({d+1,{x,y+1}});
        }
    }
    no;
}

