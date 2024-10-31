// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m;

inline void solve(void){
    cin>>n>>m;
    int x=(n*(n+1)-1)%m+1;
    if(n<x)cout<<"Alice\n";
    else cout<<"Bob\n";
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
