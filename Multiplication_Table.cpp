// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;

inline int f(int x){
    int ans=0;
    for(int i=1;i<=n;i++)ans+=min(n,x/i);
    return ans;
}

signed main(void){
    cin>>n;

    int l=0,r=n*n+1;
    while(r-l>1){
        //cerr<<l<<","<<r<<endl;
        int m=l+r>>1;
        int a=f(m);
        //cerr<<m<<"->"<<a<<endl;
        if(a<(n*n+1)/2)l=m;
        else r=m;
    }
    cout<<r<<endl;
}
