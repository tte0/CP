// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
string s;

inline void solve(void){
    cin>>n>>s;
    vector<int> pref(n+1);
    for(int i=0;i<n;i++){
        pref[i+1]=pref[i]+(s[i]=='1'?1:-1);
    }

    sort(pref.begin(),pref.end());

    int ans=0;
    for(int i=0;i<=n;i++){
        ans+=pref[i]*(2*i-n)+i*(n-i+1);
    }

    cout<<ans/2<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
