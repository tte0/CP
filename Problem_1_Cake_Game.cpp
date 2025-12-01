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

    int sum=0,cnt=(n/2-1);
    for(int i=n-cnt;i<n;i++){
        sum+=v[i];
    }

    int ans=sum;
    for(int i=0;i<cnt;i++){
        sum+=v[i];
        sum-=v[n-cnt+i];
        ans=max(ans,sum);
    }

    int ans2=-ans;
    for(int i=0;i<n;i++)ans2+=v[i];
    cout<<ans2<<" "<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
