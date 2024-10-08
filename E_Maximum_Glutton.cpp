/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h>
using namespace std;
int n,x,y,dp[88][88][10004];//looked,taken,x -> y
int INF=1e9+9;
vector<int> a,b;

int main(void){
    cin>>n>>x>>y;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    for(int i=0;i<88;i++)for(int j=0;j<88;j++)for(int k=0;k<10004;k++)dp[i][j][k]=INF;

    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<=x;k++){
                if(dp[i][j][k]>y)continue;
                dp[i+1][j][k] = min(dp[i+1][j][k] , dp[i][j][k]);
                if(k+a[i] <= x) dp[i+1][j+1][k+a[i]] = min(dp[i+1][j+1][k+a[i]] , dp[i][j][k]+b[i]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=x;k++){
                if(dp[i][j][k]==INF)continue;
                if(dp[i][j][k]>y)ans=max(ans,j);
                else ans=max(ans,j+1);
            }
        }
    }
    ans = min(ans , n);
    cout<<ans<<endl;
}
