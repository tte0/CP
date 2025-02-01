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
    
    int ans=0;
    for(int i=0;i<n;i++){
        set<int> st;
        for(int i=0;i<=n;i++)st.insert(i);
        for(int j=i;j<n;j++){
            st.erase(v[j]);
            ans+=*st.begin();
        }
    }

    cout<<ans<<endl;
}
