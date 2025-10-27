// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m;
vector<int> v;

signed main(void){
    cin>>n>>m;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> dp(n+1);
    multiset<int> st;st.insert(0);
    for(int i=1;i<=n;i++){
        dp[i]=v[i-1]+*(st.begin());
        st.insert(dp[i]);
        if(0<=i-m)st.erase(st.find(dp[i-m]));
    }

    int ans=INT64_MAX;
    for(int i=n-m;i<n;i++){
        ans=min(ans,dp[i+1]);
    }
    

    cout<<ans<<endl;
}
