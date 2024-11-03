// Author: Teoman Ata Korkmaz
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2")
#pragma GCC optimize("unroll-loops,no-stack-protector,O3,fast-math")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=200005;
///////////////////////////////////////////////////////////
int n,sieve[N],miu[N],ans,vis[N];
vector<int> v,primes,cnt(N);
vector<int> divs[N];

inline void init(){
    for(int i=2;i<N;i++){
        if(sieve[i])continue;
        primes.push_back(i);
        for(int j=i*i;j<N;j+=i)sieve[j]=i;
    }
    for(int i=2;i<N;i++)miu[i]=1;
    for(int i=2;i<N;i++){
        for(int j=i<<1;j<N;j+=i)miu[j]-=miu[i];
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i)divs[j].push_back(i);
    }
    //for(int i=1;i<20;i++)cerr<<"miu["<<i<<"]="<<miu[i]<<endl;
}

inline int f(vector<int>& v){
    int ans=0;

    for(auto& i:v){
        for(auto& j:divs[i])cnt[j]++;
    }

    for(auto& i:v){
        for(auto& j:divs[i]){
            if(vis[j]++)continue;
            ans+=miu[j]*cnt[j]*(cnt[j]+1)/2;
        }
    }

    for(auto& i:v){
        for(auto& j:divs[i])cnt[j]--,vis[j]=0;
    }

    //for(auto i:v)cerr<<i<<",";
    //cerr<<endl<<ans<<endl;

    return ans;
}

signed main(void){
    init();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    for(int k=2;k<=n;k++){
        if(!miu[k])continue;

        vector<int> t;
        for(int i=k-1;i<n;i+=k){
            t.push_back(v[i]);
        }

        ans+=miu[k]*f(t);
    }

    cout<<ans<<endl;
}
