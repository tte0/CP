// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,cur,dp[12345];
vector<int> a,c;

inline int f(int x){
    if(x-c[x-1]<=cur)return int(1);
    if(dp[x])return dp[x];
    int ans=INT32_MAX;
    for(int i=1;i<=c[x-1];i++)ans=min(ans,f(x-i)+1);
    return dp[x]=ans;
};

signed main(void){
    cin>>n;
    a.resize(n-1);
    c.resize(n-1);
    for(auto& i:c)cin>>i;
    for(auto& i:a)cin>>i;

    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i-1]){
            ans+=f(i);
            cur=i;
        }
    }

    cout<<ans<<endl;
}
