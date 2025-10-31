// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

inline void solve(){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> pref(n+1);
    for(int i=0;i<n;i++)pref[i+1]=pref[i]+v[i];

    for(int i=0;i<n;i++){
        if(pref[i+1]*2==pref[n]){
            cout<<"1\n";
            for(auto i:v)cout<<i<<" ";
            cout<<endl;
            return;
        }
        if()
    }
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
