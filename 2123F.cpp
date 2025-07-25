// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e5+5;
///////////////////////////////////////////////////////////
int n,sieve[N];

inline void init(){
    sieve[1]=1;
    for(int i=2;i<N;i++){
        if(sieve[i])continue;
        for(int j=i;j<N;j+=i)sieve[j]=i;
    }
}

inline void solve(void){
    cin>>n;
    vector<int> a[n+1],p(n);
    for(int i=1;i<=n;i++)a[sieve[i]].push_back(i);

    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            p[a[i][j]-1]=a[i][(j+1)%a[i].size()];
        }
    }

    for(auto i:p)cout<<i<<" ";cout<<endl;
}

signed main(void){
    init();
    int t;
    cin>>t;
    while(t--)solve();    
}
