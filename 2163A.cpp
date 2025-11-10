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

    sort(v.begin(),v.end());
    for(int i=1;i<n-1;i+=2){
        if(v[i]!=v[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    return;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
