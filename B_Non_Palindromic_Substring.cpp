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
#define mset(x,y) memset(x,y,sizeof(x))
#define popcnt(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
#define fileio freopen("out.put","w",stdout);freopen("in.put","r",stdin)
#define usacoio(s) freopen((s + str(".in")).c_str(), "r", stdin);freopen((s + str(".out")).c_str(), "w", stdout)
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
int n,m,k,t,q,a,b,x,y,ans;
vi v;
str s;

inline void solve(void){
    cin>>n>>q>>s;
    vi g2(n,0),g3(n,0);
    for(int i=1;i<n;i++){
        g2[i]=g2[i-1];
        if(s[i]==s[i-1])g2[i]++;
    }
    for(int i=1;i<n;i++){
        g3[i]=g3[i-1];
        if(i<n-1 && s[i+1]==s[i-1])g3[i]++;
    }

    str man="@";
    for(int i=0;i<n;i++){
        man.pb('*');
        man.pb(s[i]);
    }
    man.pb('*');
    man.pb('!');
    vi p(man.size(),0);
    int l=1,r=1;
    for(int i=2;i<=2*n;i++){
        p[i]=max(int(0),min(r-i,p[l+(r-i)]));
        while(man[i-p[i]]==man[i+p[i]])p[i]++;
        if(i+p[i]>r){
            l=i-p[i];
            r=i+p[i];
        }
    }
    cerr<<"m: ";for(auto i:man)cerr<<i<<",";cerr<<endl;
    cerr<<"p: ";for(auto i:p  )cerr<<i<<",";cerr<<endl;

    while(q--){
        cin>>x>>y;
        x--;
        y--;
        if(g2[y]-g2[x]==y-x){
            cout<<0<<endl;
            continue;
        }
        if(y-x==1){
            cout<<2<<endl;
            continue;
        }
        bool isPalindrome;
        if((y-x+1)%2==0){
            isPalindrome=(p[2*(y-x+1)+1]>=y-x+1);
        }else{
            isPalindrome=(p[2*(y-x+1)]>=y-x+1);
        }

        for(int i=x;i<=(x+y)/2;i++)isPalindrome&=(s[i]==s[x+y-i]);

        if(g3[y-1]-g3[x]==y-x-1){
            cout<<2*ssum((y-x+1)/2)-((y-x+1)%2==0)*(int(isPalindrome)*(y-x+1))<<endl;
            continue;
        }  
        cout<<ssum(y-x+1)-1-(int(isPalindrome)*(y-x+1))<<endl;
    }
}

int32_t main(void){
    fastio;
    t=1;
    cin>>t;
    while(t--)solve();
}
