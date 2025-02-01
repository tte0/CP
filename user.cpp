// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,ans,ind[N];
vector<int> v;

inline int f(vector<int> v){
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=0;i<n;i++){
        assert(i<=v[i]);
        if(i!=v[i])return i;
    }
    return n;
}

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    int mex=f(v);
    for(int i=0;i<n;i++){
        if(v[i]<=mex)ind[v[i]]=i;
    }
    ind[mex]=n;

    int l=n,r=0;
    for(int i=0;i<mex;i++){
        l=min(l,ind[i]);
        r=max(r,ind[i]);
        if(ind[i+1]<l){
            ans+=(i+1)*(l-ind[i+1])*(n-r);
        }
        if(r<ind[i+1]){
            ans+=(i+1)*(l+1)*(ind[i+1]-r);
        }
        //cerr<<ans<<endl;
    }

    cout<<ans<<endl;
}
