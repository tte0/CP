/*
MIT License

Copyright (c) 2024 tte0 (teomana,teoata17)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma GCC optimize("O3,fast-math")
#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define e2(x) (1LL<<(x))
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define smrt(i) (double(sqrt(8*(i)+1)-1)/2)
#define ssum(x) ((x)*((x)+1)/2)
#define isint(x) (ceil((x))==floor((x)))
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define cendl cout<<endl
#define cflush cout.flush()
#define mset(x,y) memset(x,y,sizeof(x))
#define popcnt(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
#define fileio freopen("out.put","w",stdout);freopen("in.put","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
#define wait while(clock()-start<=0.585*CLOCKS_PER_SEC);
using namespace std;
typedef int_fast64_t ll;
typedef long double ldouble;
typedef string str;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
const int N=200005;
const int MOD=1000000007;
const ll  INF=4e18;
const double PI=4*atan(1);
inline int fp(int b,int p,int mod=MOD){int ans=1;while(p){if(p&1)ans=(ans*b)%mod;p>>=1;b=(b*b)%mod;}return ans;}
///////////////////////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,w,ans;
vi v,adj[N];
str in;
char s[101];

inline void solve(void){
    int lbnd=0,ubnd=1e14;
    int n=1;
    while(true){
        int x;
        x=n;
        printf("? %ld\n",x);fflush(stdout);
        scanf("%100s",&s);
        in=s;
        if(in=="Fired!" || in=="q")exit(0);
        if(in=="Lucky!" || in=="l"){
            lbnd=x;
            n+=x;
        }
        if(in=="Fraudster!" || in=="f"){
            ubnd=x-1;
            n-=x;
            break;
        }
        
    }
    if(lbnd==ubnd){
        cout<<"! "<<lbnd<<endl;
        return;
    }
    double searchValue=0.5;// (0,1)
    while(lbnd<ubnd){
        int m=min(ubnd,lbnd+max(int(1),int(searchValue*(ubnd-lbnd+1))));
        while(n<m){
            int x=lbnd;
            printf("? %ld\n",x);fflush(stdout);
            scanf("%100s",&s);
            in=s;
            if(in=="Fired!" || in=="q")exit(0);
            if(in=="Lucky!" || in=="l")n+=x;
            if(in=="Fraudster!" || in=="f"){
                cerr<<"(patladi: x=lbnd)"<<endl;
                exit(0);
            }
        }

        int x=m;
        printf("? %ld\n",x);fflush(stdout);
        scanf("%100s",&s);
        in=s;
        if(in=="Fired!" || in=="q")exit(0);
        if(in=="Lucky!" || in=="l"){
            lbnd=m;
            n+=m;
        }
        if(in=="Fraudster!" || in=="f"){
            ubnd=m-1;
            n-=m;
        }
    }
    printf("! %ld\n",lbnd);fflush(stdout);
    return;
}

int32_t main(void){
    t=1;
    cin>>t;
    while(t--)solve();
}
