// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> a,b;

signed main(void){
    cin>>n>>k;
    a.resize(k);    
    b.resize(k);    
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    vector<bool> vis(n+1,false);
    for(auto i:a)vis[i]=true;
    for(auto i:b)vis[i]=true;

    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=!vis[i];

    cout<<(n-k)*(n-k)-cnt<<" "<<cnt<<endl;
}
