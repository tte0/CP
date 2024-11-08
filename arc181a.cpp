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
    for(int& i:v)cin>>i;
    
    if(is_sorted(v.begin(),v.end())){
        cout<<0<<endl;
        return;
    }
    int mx=0;
    for(int i=0;i<n;i++){
        if(i==mx && i+1==v[i]){
            cout<<1<<endl;
            return;
        }
        mx=max(mx,v[i]);
    }

    cout<<((v[0]==n && v[n-1]==1)?3:2)<<endl;
}

signed main(void){
     int t;
     cin>>t;
     while(t--)solve();
}

