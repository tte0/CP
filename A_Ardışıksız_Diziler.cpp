// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int __int128_t
using namespace std;
///////////////////////////////////////////////////////////
int32_t n,k;
int dp[59][2];

signed main(void){
    cin>>n>>k;
    dp[0][0]=1;
    dp[1][0]=dp[1][1]=1;
    int sum=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-2][0]+dp[i-2][1];
    }    

    string s;
    while(n>0){
        if(k>dp[n][0]){
            s.push_back('1');
            k-=dp[n][0];
            n--;
            if(n)s.push_back('0');
        }
        else{
            s.push_back('0');
        }
        n--;
    }
    
    cout<<(k==1?s:"-1")<<endl;
}
