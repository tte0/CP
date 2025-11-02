// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> a,b;
vector<tuple<int,int,int>> ans;

signed main(void){
    cin>>n;
    a.resize(n);    
    b.resize(n);    
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    stack<int> st;
    for(int i=0;i<n;i++){
        if(a[i]<b[i])st.push(i);
        if(a[i]>b[i]){
            int x=a[i]-b[i];
            while(x && st.size()){
                int diff;
                if(x<b[st.top()]-a[st.top()]){
                    ans.push_back({st.top(),i,x});
                    a[st.top()]+=x;
                    x=0;
                }
                else{
                    ans.push_back({st.top(),i,b[st.top()]-a[st.top()]});
                    x-=b[st.top()]-a[st.top()];
                    a[st.top()]=b[st.top()];
                    st.pop();
                }
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto [a,b,c]:ans)cout<<a+1<<" "<<b+1<<" "<<c<<endl;
}
