// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#pragma GCC target("avx,avx2")
#define int int_fast64_t
using namespace std;
constexpr int N=3003;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,dp[N][N];
string s;

signed main(void){
    memset(dp,-1,sizeof(dp));
    cin>>n>>s;
    for(int i=0;i<n;i++)dp[0][i]=1;

    for(int i=1;i<n;i++){
        if(s[i-1]=='<'){
            //for(int j=0)
        }
        else{

        }    
        
    }
}
