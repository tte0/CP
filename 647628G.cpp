// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stak-protector")
#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////////////////////////
int n,dp[66000][16];
string s;

inline int pre(int x,int n){
    int x1=x,x2=x;
    for(int i=1;i<n;i++){
        bool b=(x&(1<<i))^(x&(1<<(i-1)));
        if(b){
            x1|=1<<i;
        }
        else{
            x1&=1<<i;
        }
    }
}

inline bool f(int x,int n){
    if(n==1)return x;
    int x1=x,x2=x;
    for(int i=1;i<n;i++){
        bool b=(x&(1<<i))^(x&(1<<(i-1)));
        if(b){
            x1|=1<<i;
        }
        else{
            x1&=1<<i;
        }
    }
    for(int i=n-1;i--;){
        bool b=(x&(1<<i))^(x&(1<<(i+1)));
        if(b){
            x2|=1<<i;
        }
        else{
            x2&=1<<i;
        }
    }

    if(f(x1,n-1)){
        dp[x][n]
    }
}

inline void solve(){
    memset(dp,0,sizeof(dp));
    cin>>n>>s;
    int x;
    for(int i=0;i<n;i++){
        x+=(s[i]-'0')*(1<<i);
    }

    if(f(x,n)){

    }
    else{
        cout<<0<<endl;
    }
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
