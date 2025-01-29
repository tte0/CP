// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int __int128_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
inline int f(int n){
    int ans=1;
    while(n--)ans*=10;
    ans--;
    return ans>>k;
}

void solve(void){
    int64_t n,k;
    cin>>n>>k;
    ::n=n;
    ::k=k;
    cout<<int64_t(f(n)-f(n-1))<<endl;    
}

signed main(void){
    int64_t t;
    cin>>t;
    while(t--)solve();
}