// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,arr[200005];
vector<int> v;

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> l(n,0),r(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(st.size() && v[st.top()]>=v[i])st.pop();
        if(st.size())l[i]=st.top();
        else l[i]=-1;
        st.push(i);
    }

    while(st.size())st.pop();

    for(int i=n-1;i>=0;i--){
        while(st.size() && v[st.top()]>=v[i])st.pop();
        if(st.size())r[i]=st.top();
        else r[i]=n;
        st.push(i);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,v[i]*(r[i]-l[i]-1));
    }
    
    cout<<ans<<endl;
}

