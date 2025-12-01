// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q;
string s;

inline void solve(){
    cin>>n>>q>>s;

    int cnt_qm=0,cnt_qm_big=0,cnt_small_qm=0;
    for(int i=0;i<n;i++)cnt_qm+=s[i]=='?';
    for(int i=0;i<n-1;i++)cnt_qm_big+=(s[i]=='?' && s[i+1]>'I');
    for(int i=0;i<n-1;i++)cnt_small_qm+=(s[i]=='I' && s[i+1]=='?');


    while(q--){

    }
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
