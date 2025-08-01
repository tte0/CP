// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int q;
map<int,int> mp;

signed main(void){
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        for(int i=x;i<=y;i++)mp[i]++;
        int ans=0;
        for(auto [a,b]:mp)ans+=a*b*b;
        cout<<ans<<endl;
    }    
}
