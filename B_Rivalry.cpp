// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int x,y,z;

inline void solve(void){
    cin>>x>>y>>z;
    int mn=0;
    mn=max(mn,(y+1)/2);
    mn=max(mn,z);
    if(x<mn)return void(cout<<"No"<<endl);
    if(z==0 && y%2==1)return void(cout<<"No"<<endl);
    cout<<"Yes"<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
