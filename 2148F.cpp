// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////////////////////////
inline void remove_first_k_elements(vector<vector<int>>& v,int k){
    for(auto& t:v){
        t.erase(t.begin(),t.begin()+min(k,int(t.size())));
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(auto& t:v){
        int m;
        cin>>m;
        t.resize(m);
        for(auto& i:t)cin>>i;
    }

    vector<int> ans;
    while(v.size()){
        sort(v.begin(),v.end());
        ans.insert(ans.end(),v[0].begin(),v[0].end());
        remove_first_k_elements(v,v[0].size());
        erase(v,vector<int>());
    }

    for(int i:ans)cout<<i<<" ";
    cout<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
