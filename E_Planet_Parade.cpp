// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=3e5+5;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,k,fact[N];
vector<int> v;

signed main(void){
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*i%MOD;
    cin>>n>>k;
    v.resize(n);
    for(auto& i:v)cin>>i;    
}
