// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=505;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,k;

signed main(void){
    cin>>n>>k;
    if(n==1){
        cout<<"1\n";
        return 0;
    }
    k=min(k,n*(n-1)/2-k);
    
    int dp_old[N*N/4],dp_new[N*N/4];
    memset(dp_old,0,sizeof(dp_old));
    memset(dp_new,0,sizeof(dp_new));
    dp_old[0]=1;
    for(int i=2;i<=n;i++){
        if(i>2)swap(dp_old,dp_new);
        int sum=0;
        for(int j=0;j<=min(k,i*(i-1)/2);j++){
            sum+=dp_old[j];
            if(i<=j)sum-=dp_old[j-i];
            sum=(sum%MOD+MOD)%MOD;
            dp_new[j]=sum;
        }
        //cerr<<"dp:";for(int i=0;i<=k;i++)cerr<<dp_new[i]<<",";cerr<<endl;
    }

    cout<<dp_new[k];
}
