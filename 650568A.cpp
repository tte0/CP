// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
string s;

inline void solve(){
    cin>>n>>k>>s;
    for(int i=0;i<k;i++){
        if(s[i]!=s[n-i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<(2*k==n?"NO":"YES")<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
