#pragma GCC optimize("O3,fast-math")
#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define N (100003)
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
int n,m,k,t,q,x,y;
str s,c,s2;
vi a,b,ans,zero={0},one={1},two={2};

inline vi conv(str s);
inline void printInt(vi a);
inline int sig(vi a);
inline vi neg(vi a);
inline bool smaller(vi a,vi b);
inline vi sum(vi a,vi b);
inline vi minuss(vi a,vi b);
inline vi divideByTwo(vi a);
inline vi mul(vi a,vi b);
inline vi divv(vi a,vi x);
inline vi mod(vi a,vi b);
inline vi fib(vi n);
inline vi fp(vi a,vi b);
inline vi logarithm(vi a,vi b);
inline void solve();

int32_t main(void){
    cin>>t;
    while(t--)solve();
}

inline vi conv(str s){
    vi v;
    int cnt=0;
    for(int i=0;i<int(s.size());i++){
        if(i>0 and (i-(s.size()%9))%9==0){v.pb(cnt);cnt=0;}
        cnt*=10;
        cnt+=s[i]-'0';
    }
    v.pb(cnt);
    reverse(all(v));
    return v;
}

inline void printInt(vi a){
    cout<<a.back();
    for(int i=int(a.size())-2;i>=0;i--){
        if(a[i]==0){
            cout<<"000000000";
            continue;
        }
        for(int i=0;i<9-ceil(log10(abs(a[i])));i++)cout<<0;
        cout<<abs(a[i]);
    }
}

inline int sig(vi a){
    if(a[0]<0)return -1;
    return 1;
}

inline vi neg(vi a){
    for(auto i:a)i*=-1;
    return a;
}

inline bool smaller(vi a,vi b){
    if(a.size()!=b.size())return a.size()<b.size();
    for(int i=int(a.size())-1;i>=0;i--){
        if(a[i]!=b[i])return a[i]<b[i];
    }
    return false;
}

inline vi sum(vi a,vi b){
    if(sig(a)==-1)return neg(sum(neg(a),neg(b)));
    if(sig(b)==-1)return minuss(a,neg(b));
    if(a.size()<b.size())swap(a,b);
    a.pb(0);
    for(int i=0;i<int(b.size());i++){
        a[i]+=b[i];
        a[i+1]+=a[i]/1000000000;
        a[i]%=1000000000;
    }
    while(a.size() and a.back()==0)a.pop_back();
    if(a.size()==0)a.pb(0);
    return a;
}

inline vi minuss(vi a,vi b){
    if(sig(a)==-1)return neg(minuss(neg(a),neg(b)));
    if(sig(b)==-1)return sum(a,neg(b));
    if(smaller(a,b)){
        vi ans=minuss(b,a);
        ans.back()*=-1;
        return ans;
    }
    for(int i=int(b.size())-1;i>=0;i--){
        if(a[i]<b[i]){
            a[i]+=1000000000;
            a[i+1]-=1;
        }
        a[i]-=b[i];
    }
    for(int i=0;i<int(a.size());i++){
        if(a[i]<0){
            a[i+1]-=1;
            a[i]+=1000000000;
        }
    }
    while(a.size() and a.back()==0)a.pop_back();
    if(a.size()==0)a.pb(0);
    return a;
}

inline vi divideByTwo(vi a){
    if(sig(a)==-1)return neg(divideByTwo(neg(a)));
    for(int i=int(a.size())-1;i>0;i--){
        a[i-1]+=1000000000*(a[i]%2);
        a[i]/=2;
    }
    a[0]/=2;
    while(a.size() and a.back()==0)a.pop_back();
    if(a.size()==0)a.pb(0);
    return a;
}

inline vi mul(vi a,vi b){
    if(sig(a)==-1)return neg(mul(neg(a),b));
    if(sig(b)==-1)return neg(mul(neg(b),a));
    //cout<<"girdi: mul(";printInt(a);cout<<",";printInt(b);cout<<")"<<endl;
    if(smaller(a,b))swap(a,b);
    if(b==zero)return zero;
    if(b==one)return a;
    vi alt=mul(a,divideByTwo(b));
    alt=sum(alt,alt);
    if(b[0]%2)alt=sum(alt,a);
    //cout<<"cikti: mul(";printInt(a);cout<<",";printInt(b);cout<<")"<<endl;
    return alt;
}

inline vi divv(vi a,vi x){
    if(x==two)return divideByTwo(x);
    if(sig(a)==-1)return neg(divv(neg(a),b));
    if(sig(x)==-1)return neg(divv(a,neg(b)));
    //cout<<"girdi: divv(";printInt(a);cout<<",";printInt(x);cout<<")"<<endl;
    if(smaller(a,x))return zero;
    vi l=zero,r=sum(a,one);
    while(smaller(l,r)){
        vi m=divideByTwo(sum(l,r));
        printInt(m);cendl;
        vi b=mul(m,x);
        if(smaller(b,a) or b==a)l=sum(m,one);
        else r=m;
    }
    //cout<<"cikti: divv(";printInt(a);cout<<",";printInt(x);cout<<")"<<endl;
    return minuss(l,one);
}

inline vi mod(vi a,vi b){
    if(smaller(b,one))return {-1};
    return minuss(a,mul(b,divv(a,b)));
}

inline vi fib(vi n){
    if(sig(n)==-1)return {-1};
    vi a,b,q,p;
    a=q=one;
    b=p=zero;
    while(smaller(zero,n)){
        if(mod(n,two)==zero){
            vi qq=mul(q,q);
            q=sum(mul(mul(q,two),p),qq);
            p=sum(mul(p,p),qq);
            n=divideByTwo(n);
        }
        else{
            vi aq=mul(a,q);
            a=sum(aq,sum(mul(b,q),mul(a,p)));
            b=sum(mul(b,p),aq);
            n=minuss(n,one);
        }
    }
    cendl;
    return b;
}

inline vi fp(vi a,vi b){
    if(sig(b)==-1)return zero;
    //cout<<"girdi: fp(";printInt(a);cout<<",";printInt(b);cout<<")"<<endl;
    if(b==zero)return one;
    vi t=fp(a,divideByTwo(b));
    t=mul(t,t);
    if(b[0]%2)t=mul(t,a);
    //cout<<"cikti: fp(";printInt(a);cout<<",";printInt(b);cout<<")"<<endl;
    return t;
}

inline vi logarithm(vi a,vi b){
    if(sig(a)==-1 or sig(b)==-1)return {-1};
    vi cnt=zero;
    while(a!=zero){
        a=divv(a,b);
        cnt=sum(cnt,one);
    }
    return minuss(cnt,one);
}

inline void solve(){
    cin>>s>>c;
    a=conv(s);
    if(c=="fib"){
        printInt(fib(a));
        cendl;
        return;
    }
    cin>>s2;
    b=conv(s2);
    if(c=="<"){
        if(smaller(a,b))cout<<"true"<<endl;
        else cout<<"false"<<endl;
        return;
    }
    else if(c=="="){
        if(a==b)cout<<"true"<<endl;
        else cout<<"false"<<endl;
        return;
    }
    else if(c==">"){
        if(smaller(b,a))cout<<"true"<<endl;
        else cout<<"false"<<endl;
        return;
    }
    else if(c=="+"){
        ans=sum(a,b);
    }
    else if(c=="-"){
        ans=minuss(a,b);
    }
    else if(c=="*"){
        ans=mul(a,b);
    }
    else if(c=="^"){
        ans=fp(a,b);
    }
    else if(c=="/"){
        ans=divv(a,b);
    }
    else if(c=="log"){
        ans=logarithm(a,b);
    }
    else if(c=="%"){
        ans=mod(a,b);
    }
    printInt(ans);
    cendl;
    return;
}
