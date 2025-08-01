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
    
    int l=0,r=0,ans=0;
    set<int> st;
    while(l<n){
        while(r<n && st.find(v[r])==st.end())st.insert(v[r++]);
        ans+=r-l;
        st.erase(v[l++]);
    }

    cout<<ans<<endl;
}
