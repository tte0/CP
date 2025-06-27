// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

inline void debug(stack<pair<int,int>> st){
    stack<pair<int,int>> temp;
    while(st.size()){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()){
        cerr<<"["<<temp.top().first<<","<<temp.top().second<<"] ";
        temp.pop();
    }
    cerr<<endl;
}

inline void solve(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> pref(n);
    for(int i=0;i<n;i++)pref[i]=v[i]+i;
    for(int i=1;i<n;i++)pref[i]=max(pref[i],pref[i-1]);
    
    int ans=0,best=v[0]+v[1];
    stack<pair<int,int>> st;//{val,ind}
    if(v[0]>=v[1])st.push({v[0],0});
    st.push({v[1],1});
    for(int i=2;i<n;i++){
        ans=max(ans,(v[i]-i)+best);
        //debug(st);
        //cerr<<"best,ans:"<<best<<","<<ans<<endl<<endl;

        while(st.size() && st.top().first<v[i]){
            st.pop();
        }
        best=max(best,v[i]+pref[i-1]);
        if(st.size())best=max(best,st.top().first+v[i]+st.top().second);
        st.push({v[i],i});
    }

    cout<<ans<<endl;
    //cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
