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
typedef map<int,str> mis;
typedef map<char,int> mci;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
/////////////////////////////////////////////////////////////
int n=8,m,k,t,x,y,ans;//449*445
int base=19,base2=277,mod=MOD,mod2=987654319;
int ahash=0,bhash=0;
str a,b,c,d;
mis mp,mp2;

int fp(int b,int p,int mod){
    if(p==0)return 1;
    int t=fp(b,p/2,mod);
    t=(t*t)%mod;
    if(p%2)t=(t*b)%mod;
    return t;
}

int32_t main(void){
    srand(time(NULL));
    while(true){
        str s;
        for(int i=0;i<n;i++){
            s.pb(rand()%26+'a');
        }
        int hash=0;
        for(int i=0;i<n;i++){
            hash+=(fp(base,i,mod)*(s[i]-'a'+1))%mod;
            hash=hash%mod;
        }
        if(mp[hash]!="" && mp[hash]!=s){
            a=s;
            b=mp[hash];
            break;
        }
        mp[hash]=s;
    }
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<endl;

    for(int i=0;i<n;i++){
        ahash+=(fp(base2,i,mod2)*(a[i]-'a'+1))%mod2;
        bhash+=(fp(base2,i,mod2)*(b[i]-'a'+1))%mod2;
        ahash=ahash%mod2;
        bhash=bhash%mod2;
    }
    cout<<"ahash: "<<ahash<<endl<<"bhash: "<<bhash<<endl<<endl;
    n=35;
    while(true){
        str s;
        int hash=0;
        for(int i=0;i<n;i++){
            if(rand()%2){
                for(int j=0;j<a.size();j++){
                    s.pb(a[j]);
                }
            }
            else{
                for(int j=0;j<b.size();j++){
                    s.pb(b[j]);
                }
            }
        }
        for(int i=0;i<s.size();i++){
            hash+=(fp(base2,i,mod2)*(s[i]-'a'+1))%mod2;
            hash=hash%mod2;
        }
        if(mp2[hash]!="" and mp2[hash]!=s){
            c=s;
            d=mp2[hash];
            while(c.size() && c.back()==d.back()){
                c.pop_back();
                d.pop_back();
            }
            reverse(all(c));
            reverse(all(d));
            while(c.size() && c.back()==d.back()){
                c.pop_back();
                d.pop_back();
            }
            reverse(all(c));
            reverse(all(d));
            cout<<"normal:"<<endl<<c<<endl<<d<<endl<<endl;
            reverse(all(c));
            reverse(all(d));
            cout<<"reverse:"<<endl<<c<<endl<<d<<endl<<endl;
            reverse(all(c));
            reverse(all(d));
            break;
        }
        mp2[hash]=s;
    }
    int hash1=0,hash2=0;
    for(int i=0;i<c.size();i++){
        hash1+=(fp(base,i,mod)*(c[i]-'a'+1))%mod;
        hash1=hash1%mod;
        hash2+=(fp(base2,i,mod2)*(c[i]-'a'+1))%mod2;
        hash2=hash2%mod2;
    }
    cout<<"c >> hash1: "<<hash1<<" "<<"hash2: "<<hash2<<endl;

    hash1=0,hash2=0;
    for(int i=0;i<d.size();i++){
        hash1+=(fp(base,i,mod)*(d[i]-'a'+1))%mod;
        hash1=hash1%mod;
        hash2+=(fp(base2,i,mod2)*(d[i]-'a'+1))%mod2;
        hash2=hash2%mod2;
    }
    cout<<"d >> hash1: "<<hash1<<spc<<"hash2: "<<hash2<<endl;
}
