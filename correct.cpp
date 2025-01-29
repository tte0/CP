// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;

inline void solve(void){
    cin>>n>>k;    
    int l=1,r=10;
    while(--n)l*=10,r*=10;
    int ans=0;
    for(int i=l;i<r;i++){
        if(i%(1LL<<k)==0)ans++;
    }
    cout<<ans<<endl;
}

signed main(void){
    int64_t t;
    cin>>t;
    while(t--)solve();
}
