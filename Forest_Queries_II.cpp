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
int n,m,k,t,q,x,y,x1,x2,yy1,y2,w,ans;
int arr[1000][1000],st[4000][4000];
char c;

    
int build(int u,int d,int l,int r,int xnode,int ynode){
    cerr<<">>build u,d,l,r,xnode,ynode : "<<u<<","<<d<<","<<l<<","<<r<<","<<xnode<<","<<ynode<<endl;
    if(u==d){
        if(r==l)return st[xnode][ynode]=arr[u][l];
        int m=(l+r)/2;
        return st[xnode][ynode]=build(u,d,l,m,xnode,ynode*2)+build(u,d,m+1,r,xnode,ynode*2+1);
    }
    int m=(u+d)/2;
    return st[xnode][ynode]=build(u,m,l,r,xnode*2,ynode)+build(m+1,d,l,r,xnode*2+1,ynode);
}


int query(int u,int d,int l,int r,int xnode,int ynode){
    cerr<<">>query u,d,l,r,xnode,ynode : "<<u<<","<<d<<","<<l<<","<<r<<","<<xnode<<","<<ynode<<endl;
    if(d<x1 or u>x2 or r<yy1 or l>y2)return 0;
    if(x1<=u and d<=x2){
        if(yy1<=l and r<=y2)return st[xnode][ynode];
        int m=(l+r)/2;
        return query(u,d,l,m,xnode,ynode*2)+query(u,d,m+1,r,xnode,ynode*2+1);
    }
    int m=(u+d)/2;
    return query(u,m,l,r,xnode*2,ynode)+query(m+1,d,l,r,xnode*2+1,ynode);
}

int update(int u,int d,int l,int r,int xnode,int ynode){
    cerr<<">>update u,d,l,r,xnode,ynode : "<<u<<","<<d<<","<<l<<","<<r<<","<<xnode<<","<<ynode<<endl;
    if(d<x or u>x or r<y or l>y)return st[xnode][ynode];
    if(x==u and d==x){
        if(y==l and r==y)return st[xnode][ynode]=1-st[xnode][ynode];
        int m=(l+r)/2;
        return st[xnode][ynode]=update(u,d,l,m,xnode,ynode*2)+update(u,d,m+1,r,xnode,ynode*2+1);
    }
    int m=(u+d)/2;
    return st[xnode][ynode]=update(u,m,l,r,xnode*2,ynode)+update(m+1,d,l,r,xnode*2+1,ynode);
}

int32_t main(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(c!='.')arr[i+1][j+1]=1;
            else arr[i+1][j+1]=0;
        }
    }
    cerr<<"input ok"<<endl;
    build(1,n,1,n,1,1);
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cerr<<st[i][j]<<",";
        }
        cerr<<endl;
    }
    cerr<<"build ok"<<endl;
    while(q--){
        cin>>x;
        if(x==2){
            cin>>x1>>yy1>>x2>>y2;
            cout<<query(1,n,1,n,1,1)<<endl;
            //cerr<<"query ok"<<endl;
        }
        else{
            cin>>x>>y;
            update(1,n,1,n,1,1);
            /*cerr<<"update ok"<<endl;
            for(int i=1;i<=10;i++){
                for(int j=1;j<=10;j++){
                    cerr<<st[i][j]<<",";
                }
                cerr<<endl;
            }*/
        }
    }
    cerr<<"kod ok iste daha ne istiyon";
    //cout<<"kod ok iste daha ne istiyon";
}
