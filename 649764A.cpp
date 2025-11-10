// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n=10,cnt[11];

signed main(void){
    int mx=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mx=max(++cnt[x],mx);
    }    
    for(int i=11;i--;){
        if(cnt[i]==mx){
            cout<<i<<endl;
            return 0;
        }
    }
}
