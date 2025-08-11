// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> v;

inline void solve(void){
    cin>>n>>k;
    v.resize(n);
    for(auto& i:v)cin>>i;
    sort(v.begin(),v.end());

    vector<int> arr(n,-1);
    for(int i=n;i--;){
        if(2*v[i]>=v[i+1])arr[i]=arr[i+1];
        else arr[i]=2*arr[i];
    }

    int ans=n;
    int ind=upper_bound(v.begin(),v.end(),k)-v.begin()-1;
    while(k!=-1 && ind<n-1){
        if(ind==-1 || 2*v[ind]<k){
            while(k<v[ind])k*=2,ans++;
        }
        
    }
    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
