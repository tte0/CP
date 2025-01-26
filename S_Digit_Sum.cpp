// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=10004;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,k,dp[N][105][2];
string s;
vector<int> x;

inline int f(int ind=0,int d=0,int b=1){
    if(ind==n)return !d;
    if(dp[ind][d][b]!=-1)return dp[ind][d][b];
    int ans=0;
    if(b==0){
        for(int i=0;i<10;i++){
            ans+=f(ind+1,(d+i)%k,0);
            ans%=MOD;
        }
    }
    else{
        for(int i=0;i<x[ind];i++){
            ans+=f(ind+1,(d+i)%k,0);
            ans%=MOD;
        }
        ans+=f(ind+1,(d+x[ind])%k,1);
        ans%=MOD;
    }
    return dp[ind][d][b]=ans;
}

signed main(void){
    memset(dp,-1,sizeof(dp));
    cin>>s>>k;
    n=s.size();
    for(auto c:s)x.push_back(c-'0');

    cout<<(f()-1+MOD)%MOD<<endl;
}
