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
////////////////n///////////////////////////////////////////////////
int n,m,k,t,q,a,b,x,y,z,ans;
vector<str> alphabet={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};


inline int hashString(const str& s,const int& base,const int& mod){
    int ans=0,k=1,n=s.size();
    for(int i=0;i<n;i++){
        ans=(ans+(s[i]-'a')*k)%mod;
        k=(k*base)%mod;
    }
    return ans;
}

inline void generateString(const vector<str>& alphabet,str& s,const int length){
    for(int i=0;i<length;i++)s.append(alphabet[rand()%alphabet.size()]);
}

inline void shorten(str& s,str& q){
    while(q.back() == s.back()){
        s.pop_back();
        q.pop_back();
    }
    reverse(all(s));
    reverse(all(q));
    while(s.back() == q.back()){
        s.pop_back();
        q.pop_back();
    }
    reverse(all(s));
    reverse(all(q));
}

inline vector<str> generateAlphabet(const vector<str>& alphabet,const int& base,const int& mod,const int& limit=1.4e10){
    unordered_map<int,str> mp;
    int n=(alphabet.size()>2?7:20),hash;
    str s,q; 
    while(true){
        s="";
        generateString(alphabet,s,n);
        hash=hashString(s,base,mod);

        //cerr<<s<<spc<<hash<<endl;

        if(mp[hash]!="" && mp[hash]!=s){
            q=mp[hash];
            break;
        }
        if(s.size()*mp.size()<limit)mp[hash]=s;
    }

    shorten(s,q);
    
    return {s,q};
}



int32_t main(void){
    srand(time(NULL));
    cout<<"How many hash: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"base: ";cin>>x;
        cout<<"mod : ";cin>>y;
        if(i>2)alphabet=generateAlphabet(alphabet,x,y);
        else alphabet=generateAlphabet(alphabet,x,y);
    }

    freopen("normal.txt","w",stdout);
    for(auto& i:alphabet)cout<<i<<endl;

    for(auto& i:alphabet)reverse(all(i));

    freopen("reverse.txt","w",stdout);
    for(auto& i:alphabet)cout<<i<<endl;
}
