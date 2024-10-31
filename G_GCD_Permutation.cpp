// Author: Teoman Ata Korkmaz
#pragma GCC optimize()
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////

inline void f(int n){
    int cnt=0;
    for(int x=1;x<=n;x++){
        for(int i=1;i<=x;i++){
            if(gcd(i,x)!=1)cnt++;
        }
    }
    cout<<"f("<<n<<") : "<<cnt<<endl;
}

signed main(void){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)f(i);
}
