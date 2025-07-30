// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q;
vector<int> v;

signed main(void){
    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    while(q--){
        int x,y,z;
        cin>>x;
        if(x==1){
            cin>>x>>y;
            int ans=0;
            for(int i=x-1;i<y;i++)ans+=v[i];
            cout<<ans<<endl;
        }
        else if(x==2){
            cin>>x>>y>>z;
            for(int i=x-1;i<y;i++)v[i]%=z;
        }
        else{
            cin>>x>>y;
            v[x-1]=y;
        }
    }
}
