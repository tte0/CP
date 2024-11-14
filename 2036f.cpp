// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int l,r,i,k;

inline int range(int l,int r){
    if(l>r)return 0;
    if(l)return range(0,l-1)^range(0,r);
    if(r%4==0)return r;
    if(r%4==1)return 1;
    if(r%4==2)return r+1;
    if(r%4==3)return 0;
}

inline int count(int n){
    return n/(1<<i)+(n%(1<<i)>=k);
}

inline int f(){
    int cntl=count(l-1),cntr=count(r);
    int rhs=((cntr-cntl)&1)*k;
    int lhs=range(cntl,cntr-1)<<i;
    // cerr<<"cntl:"<<cntl<<endl;
    // cerr<<"cntr:"<<cntr<<endl;
    // cerr<<"lhs :"<<lhs <<endl;
    // cerr<<"rhs :"<<rhs <<endl;
    return lhs^rhs;
}

inline void solve(){
    cin>>l>>r>>i>>k;
    int x=range(l,r);
    int y=f();
    // cerr<<"x:"<<x<<endl;
    // cerr<<"y:"<<y<<endl;
    cout<<(x^y)<<endl;
    // cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}

