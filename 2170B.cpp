// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;

inline void solve(){
    cin>>n;
    int cnt=0,sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt+=x!=0;
        sum+=x;
    }
    cout<<min(cnt,sum-n+1)<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
