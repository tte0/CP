// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,x;

inline void solve(void){
    cin>>n>>x;
    if(n==1 && x==0){
        cout<<-1<<endl;
        return;
    }
    if(x==0 || x==1){
        if(n%2==x)cout<<n<<endl;
        else cout<<n+3<<endl;
        return;
    }
    int y=n-__builtin_popcount(x);
    if(y<=0)cout<<x<<endl;
    else cout<<x+y+y%2<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
