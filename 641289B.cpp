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
    reverse(v.begin(),v.end());
    for(auto i:v)cout<<i<<" ";
}
