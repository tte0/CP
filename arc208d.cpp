// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

inline void Swap(int i,int j){
    
}

inline void solve(){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    for(auto& i:v)--i;

    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]==i)cnt++;
        if(v[v[i]]!=i){
            cout<<"No"<<endl;
            return;
        }
    }
    if(cnt!=1){
        cout<<"No"<<endl;
        return;
    }

    vector<vector<int>> ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=(i+j)%n;
        }
    }

    vector<int> inv(n);
    for(int i=0;i<n;i++)inv[v[i]]=i;

    for(int i=0;i<n;i++){
        while(inv[ans[i][i]]!=i){
            Swap(inv[ans[i][i]],i);
        }
    }
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
