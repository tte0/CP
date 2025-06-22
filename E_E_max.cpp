// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=998244353;
///////////////////////////////////////////////////////////
int n;
vector<array<int,6>> v;
vector<int> c;

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& arr:v){
        for(int i=0;i<n;i++){
            static int x;
            cin>>x;
            arr[i]=x;
            c.push_back(x);
        }
    }

    sort(c.begin(),c.end());
    c.resize(unique(c.begin(),c.end())-c.begin());

    int mx=-1;
    for(auto arr:v){
        int mn=2e9;
        for(auto i:arr){
            mn=min(mn,i);
        }
        mx=max(mx,mn);
    }

    
}
