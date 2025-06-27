// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
#ifdef ONLINE_JUDGE
    #define cerr if(0)cerr
#endif
using namespace std;
constexpr int N=3e5+5;
///////////////////////////////////////////////////////////

inline void solve(void){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto& i:v)cin>>i;

    int ans=0;
    for(int i=0;i<n-2;i++){
        int mx1=max(v[i],v[i+1]),mx2=min(v[i],v[i+1]),mx3=INT32_MIN;
        for(int j=i+2;j<n;j++){
            if(v[j]<=mx3);
            else if(v[j]<=mx2){
                mx3=v[j];
            }
            else if(v[j]<=mx1){
                mx3=mx2;
                mx2=v[j];
            }
            else{
                mx3=mx2;
                mx2=mx1;
                mx1=v[j];
            }
            ans=max(ans,mx1+mx2+mx3-(j-i));
        }
    }

    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
