// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m,x,y;

signed main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        cout<<min(x,y)<<" "<<max(x,y)<<endl;
    }    
}
