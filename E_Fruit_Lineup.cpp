// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=998244353;
constexpr int N=3e6+5;
///////////////////////////////////////////////////////////
int a,b,c,d,ans,fact[N]={1};

inline int fp(int b,int p=MOD-2){
    int ans=1;
    while(p){
        if(p&1)ans=ans*b%MOD;
        p>>=1;
        b=b*b%MOD;
    }
    return ans;
}

inline int nCr(int n,int r){
    return fact[n]*fp(fact[r]*fact[n-r]%MOD)%MOD;
}

signed main(void){
    for(int i=0;++i<N;)fact[i]=fact[i-1]*i%MOD;
    cin>>a>>b>>c>>d;

    int ans=0;
    for(int i=0;i<=c;i++){
        int l=nCr(i+a+b,i+a);
        int r=nCr(c-i+d-1,c-i);
        //cerr<<"l,r:"<<l<<","<<r<<endl;
        ans=(ans+l*r)%MOD;
    }

    cout<<ans<<endl;
}
