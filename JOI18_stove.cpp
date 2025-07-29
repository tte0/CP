// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> v;

signed main(void){
    cin>>n>>k;
    v.resize(n);
    for(auto& i:v)cin>>i;

    for(int i=0;i<n-1;i++)v[i]=v[i+1]-v[i]-1;
    v.pop_back();
    sort(v.begin(),v.end());

    while(--k){
        v.pop_back();
    }

    for(int i:v)n+=i;
    cout<<n<<endl;
}
