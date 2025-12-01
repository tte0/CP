// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=503;
///////////////////////////////////////////////////////////
int n,m,l,ans,cost[N][N]/*making i-th class j mod m*/;
vector<int> v,arr[N];

signed main(void){
    cin>>n>>m>>l;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        arr[i%l].push_back(v[i]);
    }

    for(int s=0;s<l;s++){
        for(int x=0;x<m;x++){
            for(const auto& i:arr[s]){
                cost[s][x]+=(x+m-i)%m;
            }
        }
    }

    /*for(int s=0;s<l;s++){
        cerr<<"cost: ";
        for(int i=0;i<m;i++){
            cerr<<cost[s][i]<<" ";
        }cerr<<endl;
    }cerr<<endl;*/

    vector<int> dp(m,INT64_MAX/4);
    dp[0]=0;
    for(int s=0;s<l;s++){
        vector<int> dp_new(m,INT64_MAX/4);
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                dp_new[(i+j)%m]=min(dp_new[(i+j)%m],dp[i]+cost[s][j]);
            }
        }
        swap(dp,dp_new);
        //cerr<<"dp: ";for(auto i:dp)cerr<<i<<" ";cerr<<endl;
    }

    cout<<dp[0]<<endl;
}
