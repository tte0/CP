// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e4+5;
constexpr int B=1e5+5;
///////////////////////////////////////////////////////////
int n,b,v[N];
bitset<B> bt,res;

inline bool f(int mx){
    bt.reset();bt[0]=1;
    //cerr<<"mx:"<<mx<<endl;
    //cerr<<bt<<endl;
    for(int i=0;i<n;i++){
        res.reset();
        int cnt=0,p=mx;
        while(p){
            if(p&1)res=(res<<(v[i]<<cnt))|bt;
            p>>=1;
            bt|=bt<<(v[i]<<cnt);
            cnt++;
        }
        bt=res;
    }
    //cerr<<endl;
    return bt[b];
}

signed main(void){
    cin>>n>>b;
    for(int i=0;i<n;i++)cin>>v[i];

    int l=0,r=b+2;
    while(l<r){
        int m=(l+r)>>1;
        if(f(m))r=m;
        else l=m+1;
    }

    cout<<(l==b+2?-1:l-1)<<endl;
}
