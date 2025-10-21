// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,digit[10]={1,2,4,8,6};

signed main(void){
    cin>>n;
    cout<<digit[(n-1)%4+1];
}
