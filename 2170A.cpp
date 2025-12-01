// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e2+5;
///////////////////////////////////////////////////////////
int n,arr[N][N];

inline void solve(){
    cin>>n;
    for(int i=0;i<=n+1;i++)arr[i][0]=arr[i][n+1]=arr[0][i]=arr[n+1][i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i+1][j+1]=i*n+j+1;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans=max(ans,arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i-1][j]+arr[i][j-1]);
        }
    }

    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
