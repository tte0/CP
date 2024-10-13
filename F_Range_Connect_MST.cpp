// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q,ans;
vector<pair<int,pair<int,int>>> v;

signed main(void){
    cin>>n>>q;
    v.resize(q);
    for(auto& i:v)cin>>i.second.first>>i.second.second>>i.first;
    sort(v.begin(),v.end());

    set<int> st;
    for(int i=1;i<=n;i++) st.insert(i);

    for(auto& _:v){
        int l=_.second.first,r=_.second.second,c=_.first;
        if(st.lower_bound(l)==st.lower_bound(r))continue;

        auto it=st.lower_bound(l);
        while(!(it==st.end() || r<*it)){
            ans+=c;
            auto it2=it;
            it2++;
            if(!(it2==st.end() || r<*it2))st.erase(it);
            it++;
            for(auto i:st)cerr<<i<<",";cerr<<endl;
        }

        for(auto i:st)cerr<<i<<",";cerr<<endl;
    }

    cout<<ans<<endl;
}
