// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m;
vector<int> v;

inline void solve(){
    cin>>n>>m;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    for(auto& i:v)i%=m;
    sort(v.begin(),v.end());

    int ans=1e18,sum=0;
    for(int i=0;i<n;i++)sum+=v.back()-v[i];

    ans=min(ans,sum);

    for(int i=n;--i;){
        sum+=m-n*(v[i]-v[i-1]);
        ans=min(ans,sum);
    }

    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
