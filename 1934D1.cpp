// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m;

inline int msb(int x){
    return 31-__builtin_clz(x);
}

inline void solve(void){
    cin>>n>>m;
    if(!(n & (n-1))){
        cout<<"-1\n";
        return;
    }

    int a=msb(n),b=msb(n ^ (1<<msb(n)));
    
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
