// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=402;
///////////////////////////////////////////////////////////
int n,k;
uint_fast64_t dp[N][N][N],mn[N];//ind,rem,cur
vector<int> v;

signed main(void){
    memset(dp,-1,sizeof(dp));
    memset(mn,-1,sizeof(mn));
    cin>>n>>k;
    
    mn[k]=dp[0][k][0]=0;
    for(int i=1;i<n;i++){
        for(int r=0;r<=k;r++){

        }
        memset(mn,-1,sizeof(mn));
    }
}

