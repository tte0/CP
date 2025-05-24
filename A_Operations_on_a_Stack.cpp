// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    vector<int> dp(n);
    dp[0]=v[0];
    if(n>1)dp[1]=max(0L,v[0]+v[1]);
    for(int i=2;i<n;i++)dp[i]=max(dp[i-2],dp[i-1]+v[i]);

    cout<<dp[n-1]<<endl;
}
