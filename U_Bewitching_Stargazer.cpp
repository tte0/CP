// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;

inline tuple<int,int> f(int n){//ans,cnt
    if(n<k)return {0,0};
    if(n==1)return {1,1};
    auto [ans,cnt]=f(n/2);
    ans*=2;
    ans+=((n+1)/2)*cnt;
    cnt*=2;
    if(n&1){
        ans+=(n+1)/2;
        cnt++;
    }
    //err<<"f("<<n<<"): ["<<ans<<","<<cnt<<"]\n";
    return {ans,cnt};
}

inline void solve(void){
    cin>>n>>k;
    auto [ans,cnt]=f(n);
    cout<<ans<<endl;   
    cerr<<ans<<","<<cnt<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();        
}
