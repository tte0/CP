// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,dp[1<<18];
vector<int> a,b;

inline bool f(int x){
    if(dp[x]!=-1)return dp[x];
    //cerr<<"f("<<x<<")"<<endl;
    
    for(int i=0;i<n;i++){
        if(x&(1<<i))continue;
        for(int j=i+1;j<n;j++){
            if(x&(1<<j))continue;
            if((a[i]==a[j] || b[i]==b[j]) &&
               !f(x|(1<<i)|(1<<j)))
               return dp[x]=1;
        }
    }
    return dp[x]=0;
}

signed main(void){
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];

    memset(dp,-1,sizeof(dp));
    cout<<(!f(0)?"Aoki":"Takahashi")<<endl;
}
