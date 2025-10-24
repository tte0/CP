// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////

inline int fp(int b,int p){
    int ans=1;
    while(p){
        if(p&1)ans=(ans*b)%MOD;
        p>>=1;
        b=(b*b)%MOD;
    }
    return ans;
}

int n,inv_10000=fp(10000,MOD-2);
vector<int> a,p;

inline void solve(){
    cin>>n;
    a.resize(n);
    p.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:p)cin>>i;
    for(auto& i:p)i=(i*inv_10000)%MOD;

    vector<int> prob(1024);
    for(int i=0;i<n;i++){
        prob[a[i]]=prob[a[i]]*(1-p[i]) + (1-prob[a[i]])*p[i];
        prob[a[i]]=(prob[a[i]]%MOD+MOD)%MOD;
    } 

    vector<int> sum(1024,0);
    vector<int> n_sum(1024,0);
    sum[0]=1;
    for(int a=1;a<1024;a++){
        if(prob[a]==0)continue;
        for(int s=0;s<1024;s++){
            n_sum[s]=sum[s]*(1-prob[a])+sum[s^a]*prob[a];
            n_sum[s]=(n_sum[s]%MOD+MOD)%MOD;
        }
        swap(sum,n_sum);
    }

    #ifdef LOCAL
    for(int i=0;i<1024;i++){
        assert(0<=sum[i]);
        assert(sum[i]<MOD);
    }
    #endif

    int expected=0;
    for(int i=0;i<1024;i++){
        expected+=i*i*sum[i];
    }

    cout<<expected%MOD<<endl;
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();    
}
