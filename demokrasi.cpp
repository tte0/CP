/*
Author: Teoman Ata Korkmaz
*/
#pragma GCC optimize("O3,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define ssum(x) ((x)*((x)+1)/2)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
template<typename InputIterator,typename T = int>
T accumulate(InputIterator first,InputIterator last,T init = T{}) {
    for (; first != last; ++first) {
        init += *first;
    }
    return init;
}
template<typename T>inline ostream& operator<<(ostream& os,const vector<T>& a) {
    for(const T& _:a)os<<_<<' ';
    return os;
}
template<typename T>inline ostream& operator<<(ostream& os,const vector<vector<T>>& a) {
    for(const vector<T>& _:a)os<<_<<endl;
    return os;
}
template<typename T>inline istream& operator>>(istream& is,vector<T>& a) {
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
inline void debug(){cerr<<endl;}
template<typename... Args>
inline void debug(const Args&... args){
    ((cerr<<args<<' '),...)<<endl;
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
int n,m,k,t,a,b,x,y,w;
vi ans;

signed main(void){
    freopen("input.txt","r",stdin);
    input(n,m);//n=75,m=11
    vvi v(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            x--;
            v[i][x]=j;
        }
    }

    debug("v:",v);
    for(int i=0;i<n;i++){
        if(accumulate(all(v[i]))!=ssum(m-1)){
            debug("broken input at line",i);
            abort();
        }
    }

    int round=1;
    while(v[0].size()){
        vector<pair<vi,int>> cnt(m,{vi(m),0});
        for(int i=0;i<m;i++)cnt[i].ss=i;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                cnt[v[i][j]].ff[j]++;
            }
        }

        sort(rall(cnt));
        debug("ROUND",round,"RESULTS:");
        for(int i=0;i<m;i++)debug(cnt[i].ss,":",cnt[i].ff);
        int x=cnt[m-round].ss;
        ans.pb(x);
        debug();
        debug(to_string(x)+". CANDINATE ELEMINATED");
        debug("-------------------------------------------");
        
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==x){
                    v[i].erase(v[i].begin()+j);
                    break;
                }
            }
        }

        //debug("v:",v);
        round++;
    }

    reverse(all(ans));
    print("Listing (best to worst):");
    print(ans);
}
