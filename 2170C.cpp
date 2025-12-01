// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> a,b;

inline void solve(){
    cin>>n>>k;k++;
    a.resize(n);
    b.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;
    for(auto& i:a)i++;
    for(auto& i:b)i++;

    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());

    int pa=0,pb=0,ans=0;
    while(pa<n && pb<n){
        if(a[pa]*b[pb]<=k){
            ans++;
            pb++;
        }
        pa++;
    }

    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
