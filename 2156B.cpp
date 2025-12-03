// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q;
string s;

inline void solve(){
    cin>>n>>q>>s;
    bool b=false;
    for(int i=0;i<n;i++)b|=s[i]=='B';

    while(q--){
        int x;
        cin>>x;
        if(!b){
            cout<<x<<endl;
            continue;
        }
        int ans=0;
        for(int i=0;x && i<n;i=(i+1)%n,ans++){
            x=(s[i]=='A'?x-1:x/2);
        }
        cout<<ans<<endl;
    }
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)solve();   
}
