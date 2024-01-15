#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define N (200005)
#define MOD (int(1e9)+21)
#define MODL (int(1e18)+3)
#define e2(x) (1<<(x))
#define smrt(i) double(sqrt(8*(i)+1)-1)/2
#define ssum(x) (x)*((x)+1)/2
#define isint(x) ceil((x))==floor((x))
#define cno cout<<"NO"<<endl
#define cyes cout<<"YES"<<endl
#define cendl cout<<endl
#define mset(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ubnd(v,x) v.upper_bound(x)
#define lbnd(v,x) v.lower_bound(x)
#define dbg(a) cdebug()<<debug(a)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(10) 
using namespace std;
typedef long long ll;
typedef long double ldouble;
typedef string str;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<pair<char,int>> vci;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<str,int> msi;
 
int n,m,ans;
str s,q;
 
int fp(int b,int p){
    if(p==0)return 1;
    int t=fp(b,p/2);
    t=(t*t)%MOD;
    if(p%2)t=(t*b)%MOD;
    return t;
}
 
int mul(int x,int y){
    if(y==0)return 0;
    int t=mul(x,y/2);
    t=(t+t)%MOD;
    if(y%2)t=(t+x)%MOD;
    return t;
}
 
int32_t main(){
    fast;
    cin>>s>>q;
    n=s.size();
    m=q.size();
    int h1=0;
    int h2=0;
    for(int i=0;i<m;i++){
        h1+=mul(fp(37,i),s[i]-'a'+1);
        h1%=MOD;
        h2+=mul(fp(37,i),q[i]-'a'+1);
        h2%=MOD;
    }
 
    if(h1==h2)ans++;    
    //dbg(h1);dbg(h2);dbg(ans);cerr<<endl;
    for(int i=0;i<n-m;i++){
        h1-=s[i]-'a'+1;
        h1+=mul(fp(37,m),(s[i+m]-'a'+1));
        h1=mul(h1,fp(37,MOD-2));
        if(h1==h2)ans++;
        //dbg(h1);dbg(h2);dbg(ans);cerr<<endl;
    }
    cout<<ans;
    return 0;
}