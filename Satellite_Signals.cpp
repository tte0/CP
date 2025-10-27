// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,mul=1;
vector<int> a,b;

inline int fp(int b,int p,int m){
    b%=m;
    int ans=1;
    while(p){
        if(p&1)ans=(ans*b)%m;
        p>>=1;
        b=(b*b)%m;
    }
    return ans;
}

inline int phi(int x){
    int ans=0;
    for(int i=1;i<=x;i++){
        ans+=__gcd(i,x)==1;
    }
    return ans;
}

signed main(void){
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];

    for(int i=0;i<n;i++){
        b[i]=a[i]-b[i]-1;
        mul*=a[i];
    }


    int ans=0;
    for(int i=0;i<n;i++){
        mul/=a[i];
        ans+=mul*b[i]*fp(mul,phi(a[i])-1,a[i]);
        mul*=a[i];
        ans%=mul;
    }


    cout<<ans%mul+1<<endl;
}
