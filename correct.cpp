// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    int ans=1e18,mx=*max_element(v.begin(),v.end());
    for(int x=0;x<=2*mx;x++){
        int mx=0;
        for(auto i:v)mx=max(mx,i^x);
        ans=min(ans,mx);
    }
    cout<<ans<<endl;
}
