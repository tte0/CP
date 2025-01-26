// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h>
#define int int_fast64_t
using namespace std;
typedef vector<vector<int>> vvi;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,k;
vvi adj;

inline vvi mul(vvi& a,vvi& b){
    vvi ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j]+=a[i][k]*b[k][j];
                ans[i][j]%=MOD;
            }
        }
    }
    return ans;
}

signed main(void){
    cin>>n>>k;
    adj.resize(n,vector<int>(n));
    for(auto& _:adj)for(auto& i:_)cin>>i;

    vvi ans(n,vector<int>(n));
    for(int i=0;i<n;i++)ans[i][i]=1;
    while(k){
        if(k&1)ans=mul(ans,adj);
        k>>=1;
        adj=mul(adj,adj);
    }

    int cnt=0;
    for(auto _:ans)for(auto i:_)cnt=(cnt+i)%MOD;

    cout<<cnt<<endl;
}
