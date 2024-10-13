// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int INF=1e9+7;
int n,sum,dp[101][505][505];//min swap to: looked first i person, s(1)=j, s(2)=k
vector<int> a,b;

signed main(void){
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=b[i];
    }
    if(sum%3){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=0;i<101;i++)
        for(int j=0;j<505;j++)
            for(int k=0;k<505;k++)
                dp[i][j][k]=INF;

    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum/3;j++){
            for(int k=0;k<=sum/3;k++){
                if(j+b[i]<=sum/3) dp[i+1][j+b[i]][k]=min(dp[i][j][k]+(a[i]!=1) ,dp[i+1][j+b[i]][k]);
                if(k+b[i]<=sum/3) dp[i+1][j][k+b[i]]=min(dp[i][j][k]+(a[i]!=2) ,dp[i+1][j][k+b[i]]);
                                  dp[i+1][j][k]     =min(dp[i][j][k]+(a[i]!=3) ,dp[i+1][j][k]);
            }
        }
    }

    cout<<((dp[n][sum/3][sum/3]==INF)?-1:dp[n][sum/3][sum/3])<<endl;
}
