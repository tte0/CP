// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=5e5+5;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,prefr[N],prefb[N],dp[N],prefdp[N][2],lastb[N],minb[N];
string s;

inline int countr(int l,int r){
    return prefr[r]-prefr[l-1];
}

inline int countb(int l,int r){
    return prefb[r]-prefb[l-1];
}

inline int countdp(int l,int r){
    return prefdp[r][r%2]-prefdp[l-1][r%2];
}

signed main(void){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        prefr[i+1]=prefr[i]+(s[i]=='R');
        prefb[i+1]=prefb[i]+(s[i]=='B');
    }
    minb[n+1]=n+1;
    for(int i=n;i;i--){
        if(s[i]=='B')minb[i]=i;
        else minb[i]=minb[i+1];
    }

    dp[0]=1;prefdp[0][0]=1;
    int lastr=-1;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='R')lastr=i;
        if(s[i-1]=='B')lastb[i]=i;
        else lastb[i]=lastb[i-1];

        int x=1;
        while(i-x+1<=lastr && i-2*x>=0){
            if(countb(i-2*x+1,i-x)==0){
                dp[i]+=countdp(lastb[i-2*x],i-2*x);
                x=i-lastb[i-2*x]+1;
            }
            else{
                x=i-minb[i-2*x+1]+1;
            }
        }
        if(s[i-1]=='X')dp[i]+=dp[i-1];
        dp[i]%=MOD;
        prefdp[i][i%2]=(i>=2?prefdp[i-2][i%2]:0)+dp[i];
        prefdp[i][(i%2)^1]=prefdp[i-2][(i%2)^1];
    }

    cout<<dp[n]<<endl;

    //cerr<<"dp: ";for(int i=0;i<=n;i++)cerr<<dp[i]<<",";cerr<<endl;
}
