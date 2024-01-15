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
int n,m,k,t,q,x,y,ans[N][2],st[8*N];
viii ranges;
vi v;
mii compression;

inline bool cmp(iii a,iii b){
    if(a.ss.ff!=b.ss.ff)return a.ss.ff>b.ss.ff;
    return a.ss.ss<=b.ss.ss;
}

inline int query(int l,int r,int node,int x,int y){
    if(r<x || y<l)return 0;
    //cerr<<"query: l,r,node : "<<l<<" "<<r<<" "<<node<<endl;
    if(x<=l && r<=y){
        return st[node];
    }
    int mid=(l+r)/2;
    int t=query(l,mid,node*2,x,y)+query(mid+1,r,node*2+1,x,y);
    //cerr<<"return: l,r,t : "<<l<<" "<<r<<" "<<t<<endl;
    return t;
}

inline void update(int l,int r,int node){
    //cerr<<"update: l,r,node : "<<l<<" "<<r<<" "<<node;
    if(l==y && r==y){
        //cerr<<"√"<<endl;
        st[node]++;
        return;
    }
    //cerr<<endl;
    if(r<y || y<l)return;
    int mid=(l+r)/2;
    update(l,mid,node*2);
    update(mid+1,r,node*2+1);
    st[node]=st[2*node]+st[2*node+1];
    return;
}


int32_t main(void){
    fastio;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        ranges.pb({i+1,{x,y}});
        v.pb(x);
        v.pb(y);
    }
    //cerr<<"input ok"<<endl;

    sort(all(v));
    //cerr<<"v: ";for(auto i:v)//cerr<<i<<",";//cerr<<endl;
    int cnt=1;
    for(int i=0;i<v.size();i++){
        if(compression[v[i]]==0)compression[v[i]]=cnt++;
    }
    for(int i=0;i<n;i++){
        ranges[i].ss.ff=compression[ranges[i].ss.ff];
        ranges[i].ss.ss=compression[ranges[i].ss.ss];
    }
    //cerr<<"compression ok"<<endl;

    mset(st,0);
    sort(all(ranges),cmp);
    //cerr<<"ranges: ";for(auto i:ranges)//cerr<<"("<<i.ss.ff<<","<<i.ss.ss<<")"<<spc;//cerr<<endl;
    for(auto i:ranges){
        int index=i.ff;
        x=i.ss.ff,y=i.ss.ss;
        int t=query(1,2*n,1,x,y);
        //cerr<<"query ok = "<<t<<endl;
        ans[index][0]+=t;
        update(1,2*n,1);
    }
    //cerr<<endl<<"first st ok"<<endl<<endl;

    mset(st,0);
    sort(rall(ranges),cmp);
    //cerr<<"ranges: ";for(auto i:ranges)//cerr<<"("<<i.ss.ff<<","<<i.ss.ss<<")"<<spc;//cerr<<endl;
    for(auto i:ranges){
        int index=i.ff;
        x=i.ss.ff,y=i.ss.ss;
        int t=query(1,2*n,1,y,MOD);
        //cerr<<"query ok = "<<t<<endl;
        ans[index][1]+=t;
        update(1,2*n,1);
        t=st[1];
        //cerr<<"update ok = "<<t<<endl;
    }
    //cerr<<"st: ";for(int i=1;i<16;i++)//cerr<<st[i]<<",";//cerr<<endl;
    //cerr<<"second st ok"<<endl;

    for(int i=1;i<=n;i++)cout<<min(1,ans[i][0])<<" ";
    cendl;
    for(int i=1;i<=n;i++)cout<<min(1,ans[i][1])<<" ";
    //cerr<<"output ok"<<endl;
}
