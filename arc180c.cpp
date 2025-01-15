// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=102;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,dp[N][10*N][2];
vector<int> v;

inline int f(int ind=0,int sum=0,int x=1){
    if(ind>=n)return x;
    if(dp[ind][sum][x]!=-1)return dp[ind][sum][x];
    
    dp[ind][sum][x]=x;
    dp[ind][sum][x]+=f(ind+1,sum,0);
    if(sum || v[ind])dp[ind][sum][x]+=f(ind+1,sum+v[ind],1);
    
    dp[ind][sum][x]%=MOD;
    return dp[ind][sum][x];
}

signed main(void){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    v.resize(n);
    for(int& i:v)cin>>i;

    cout<<f()<<endl;
}

