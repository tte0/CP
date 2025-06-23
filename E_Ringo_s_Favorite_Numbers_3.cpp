// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e6+5;
///////////////////////////////////////////////////////////
int n,sieve[N];
vector<int> fourhundos;

inline void solve(void){
    cin>>n;
    cout<<*(--upper_bound(fourhundos.begin(),fourhundos.end(),n))<<endl;
}

void init(){
    sieve[0]=sieve[1]=0;
    for(int i=2;i<N;i++){
        if(sieve[i])continue;
        for(int j=i;j<N;j+=i)sieve[j]++;
    }
    for(int i=6;i<N;i++){
        if(sieve[i]==2)fourhundos.push_back(i*i);
    }
    sort(fourhundos.begin(),fourhundos.end());
}

signed main(void){
    init();
    int t;
    cin>>t;
    while(t--)solve();
}
