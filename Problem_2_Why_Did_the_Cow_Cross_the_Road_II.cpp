// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k,b;
vector<int> v;

signed main(void){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin>>n>>k>>b;
    v.resize(n+1,0);
    for(int i=0;i<b;i++){
        int x;
        cin>>x;
        v[x]=1;
    }
    for(int i=0;i<n;i++)v[i+1]+=v[i];

    int ans=INT32_MAX;
    for(int i=k;i<=n;i++)ans=min(v[i]-v[i-k],ans);

    cout<<ans<<endl;
}
