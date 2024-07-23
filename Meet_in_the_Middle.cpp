/*
Author: Teoman Ata Korkmaz
*/
#pragma GCC optimize("-fipa-sra,-fgcse-lm,-fgcse,inline,unroll-all-loops,no-stack-protector,O3,fast-math,Ofast")
#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define clock() (chrono::high_resolution_clock::now().time_since_epoch().count())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);cout<<fixed<<setprecision(0);cerr<<fixed<<setprecision(0)
using namespace std;
typedef int_fast32_t i32;
typedef int_fast64_t ll;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
template<typename T>
inline istream& operator>>(istream& is,vector<T>& a) {
    for(T& _:a)is>>_;
    return is;
}
inline void print(){cout<<endl;}
template<typename... Args>
inline void print(const Args&... args){
    ((cout<<args<<' '),...)<<endl;
}
inline void input(){}
template<typename... Args>
inline void input(Args&... args){
    (cin>>...>>args);
}
///////////////////////////////////////////////////////////////////
mt19937 mt(clock());
///////////////////////////////////////////////////////////////////
int n,k,ans;
vi v;

inline void solve(void){
    input(n,k);
    v.resize(n);
    input(v);
    shuffle(all(v),mt);

    vi a,b;
    a.pb(0),b.pb(0);
    for(int i=0;i<n/2;i++){
        vi _a;
        for(int& j:a)_a.pb(j),_a.pb(v[i]+j);
        swap(a,_a);
    }
    for(int i=n/2;i<n;i++){
        vi _b;
        for(int& j:b)_b.pb(j),_b.pb(v[i]+j);
        swap(b,_b);
    }

    sort(all(a));
    sort(rall(b));

    int p=0,p2=0;

    while(p<a.size() && p2<b.size()){
        if(a[p]+b[p2]<k)p++;
        else if(a[p]+b[p2]>k)p2++;
        else{
            int x=a[p],cnt=0,cnt2=0;
            while(p<a.size() && a[p]==x)cnt++,p++;
            while(p2<b.size() && b[p2]==k-x)cnt2++,p2++;
            ans+=cnt*cnt2;
        }
    }

    //debug("mp:",mp);
    //debug("mp2:",mp2);

    print(ans);
}

signed main(void){
    fastio;
    solve();
}
