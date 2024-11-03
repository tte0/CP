// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=998244353;
///////////////////////////////////////////////////////////
int n;

inline int digit(int n){
    int cnt=0;
    while(n){
        cnt++;
        n/=10;
    }
    return cnt;
}

inline int mul(int a,int b){
    return (a*b)%MOD;
}

inline int fp(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=mul(ans,a);
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}

inline int divv(int a,int b){
    return mul(a,fp(b,MOD-2));
}

signed main(void){
    cin>>n;
    int ten=fp(10,digit(n));
    //cerr<<ten;
    cout<<mul(n%MOD,divv(fp(ten,n)-1,ten-1));
}
/*
N(10^d^0+10^d^1+10^d^2+...+10^d^N-1)
*/