#pragma GCC optimize("O1,O2,O3,fast-math,trapv,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4,sse4.1,sse4.2,avx")
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
typedef map<char,int> mci;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
/////////////////////////////////////////////////////////////
int n,m,k,t,q,x,y,a,ans,countBlock[100005],nextBlock[100005],kok=320;
int nextt[100005];

int32_t main(void){
    int x,y,n,q;
    scanf("%d",&n);
    scanf("%d",&q);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        nextt[i]=x;
    }
    for(int i=n-1;i>=0;i--){
        if(i+nextt[i]>=min(n,(i/kok+1)*kok)){
            countBlock[i]=0;
            nextBlock[i]=i;
        }
        else{
            countBlock[i]=1+countBlock[i+nextt[i]];
            nextBlock[i]=nextBlock[i+nextt[i]];
        }
    }
    //cerr<<"setup ok"<<endl;
    //cerr<<"DBG: nextBlock = ";for(int i=0;i<n;i++)//cerr<<nextBlock[i]<<",";//cerr<<endl;
    //cerr<<"DBG: countBlock = ";for(int i=0;i<n;i++)//cerr<<countBlock[i]<<",";//cerr<<endl;
    while(q--){
        scanf("%d",&x);
        if(x){
            scanf("%d",&x);x--;
            int ans=1;
            while(x+nextt[x]<n){
                //cerr<<"query debug : x="<<x<<endl;
                if(nextBlock[x]==x){
                    ans++;
                    x+=nextt[x];
                }
                else{
                    ans+=countBlock[x];
                    x=nextBlock[x];
                }
            }
            printf("%d %d\n",x+1,ans);
        }
        else{
            scanf("%d%d",&x,&y);x--;
            nextt[x]=y;
            for(int i=x;i>=(x/kok)*kok;i--){
                if(i+nextt[i]>=min(n,(i/kok+1)*kok)){
                    countBlock[i]=0;
                    nextBlock[i]=i;
                }
                else{
                    countBlock[i]=1+countBlock[i+nextt[i]];
                    nextBlock[i]=nextBlock[i+nextt[i]];
                }
            }
        }
        //cerr<<"q="<<q<<" ok"<<endl;
    }
}
