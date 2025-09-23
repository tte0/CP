// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v,a;

signed main(void){
    cin>>n;
    v.resize(n);
    for(int& i:v)cin>>i;  
    a=v;  
    for(int i=1;i<n;i++)v[i]=__gcd(v[i],v[i-1]);
    int ans=0,g=0;
    for(int i=n-1;i>0;i--){
        ans=max(ans,__gcd(g,v[i-1]));
        g=__gcd(a[i],g);
        //cerr<<ans<<","<<g<<endl;
    }

    cout<<max(ans,g)<<endl;
}
