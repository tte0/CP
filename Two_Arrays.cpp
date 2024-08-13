typedef long long ll;
ll pie(ll army){return (1ll<<army);}
#include<bits/stdc++.h>
#define first fr
#define sc second
#define pb push_back
#define endl '\n'
using namespace std;

int n,m;
int a[5001],b[5001];
ll dp[5001][5001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("Input.txt","r",stdin);
    //freopen("Output.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    } 
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(0ll,max(dp[i-1][j]-a[i-1],dp[i][j-1]-b[j-1]));
            if(a[i-1]==b[j-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i-1]);
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
}