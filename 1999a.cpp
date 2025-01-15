// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;

inline void solve(){
    cin>>n;
    cout<<n%10+n/10<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

