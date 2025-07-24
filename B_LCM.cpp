// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int x,y,z;

inline void solve(void){
    cin>>x>>y>>z;
    if(x+y+1<z || max(x,y)>z)return void(cout<<"No"<<endl);
    cout<<"Yes"<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
