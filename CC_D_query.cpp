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
typedef map<char,int> mci;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
/////////////////////////////////////////////////////////////
int n,m,k,t,q,x,y,ans,kok=500;
vi v;
mii mp;
viii query;
vii queryans;
 
bool cmp(iii a,iii b){
    int t=a.ff/kok,k=b.ff/kok;
    if(t != k)return t<k;
    return a.ss.ff<b.ss.ff; 
}
 
int32_t main(void){
    cin>>n;
    int cnt=1;
    for(int i=0;i<n;i++){
        cin>>x;
        if(mp[x]==0){
            mp[x]=cnt++;
        }
        v.pb(mp[x]);
    }
    //cerr<<"v= ";for(auto i:v)cerr<<i<<",";cerr<<endl;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x>>y;x--;y--;
        query.pb({x,{y,i}});
    }
    sort(all(query),cmp);/*
    for(auto i:query){
        cerr<<"q= "<<i.ff<<","<<i.ss.ff<<","<<i.ss.ss<<endl;
    }*/
 
    int l=0,r=0,ans=1;
    int count[N];mset(count,0);
    count[v[0]]++;
    for(auto i:query){
        int x=i.ff,y=i.ss.ff;
        while(r<y){
            r++;
            if(count[v[r]]++==0)ans++;
        }
        //cerr<<"l,r,ans : "<<l<<","<<r<<","<<ans<<endl;
        while(x<l){
            l--;
            if(count[v[l]]++==0)ans++;
        }
        //cerr<<"l,r,ans : "<<l<<","<<r<<","<<ans<<endl;
        while(y<r){
            if(--count[v[r]]==0)ans--;
            r--;
        }
        //cerr<<"l,r,ans : "<<l<<","<<r<<","<<ans<<endl;
        while(l<x){
            if(--count[v[l]]==0)ans--;
            l++;
        }
        //cerr<<"l,r,ans : "<<l<<","<<r<<","<<ans<<endl;
        queryans.pb({i.ss.ss,ans});
        //cerr<<"query ok"<<endl;
    }
    sort(all(queryans));
    for(auto i:queryans)cout<<i.ss<<endl;
}