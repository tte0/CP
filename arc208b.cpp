// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;

inline int f(int n,int k){
    if(n-1>31)return 2;
    return 2+(k-1)/((1LL<<(n-1))-1);
}

inline void solve(){
    cin>>n>>k;
    
    int start=f(n,k);
    int x=start;
    vector<int> ans;
    for(int i=0;i<n;i++){
        ans.push_back(x);
        x=min(start+k,2*x-1);
    }

    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
