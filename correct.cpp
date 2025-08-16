// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e4+5;
constexpr int B=1e5+5;
///////////////////////////////////////////////////////////
int n,b,v[N];

signed main(void){
    cin>>n>>b>>n;
    cout<<(b%n?-1:b/n)<<endl;
}
