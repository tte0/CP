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

    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    
    int sum=0;
    for(const auto& i:v)sum+=i;
    
    int mx=sum;
    for(int i=1;i<n-1;i++){
        if(2*v[i-1]>=v[i+1]){
            mx=max(mx,sum+2*v.back()-v[i]);
        }
        else{
            mx=max(mx,sum+2*v[i-1]-v[i]);
        }
    }
    mx=max(mx,sum+2*v[n-2]-v[n-1]);

    cout<<mx<<endl;

    return 0;
}
