// Author: Teoman Ata Korkmaz
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2")
#pragma GCC optimize("unroll-loops,no-stack-protector,O3,fast-math")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
constexpr int MOD=998244353;
int n,k;
int sieve[1000006];

signed main(void){
    //freopen("out.txt","w",stderr);

    vector<int> primes,v,cnt;
    cin>>n>>k;
    if(2*k>n)k=n-k;

    for(int i=2;i<1000006;i++){
        if(sieve[i])continue;
        primes.push_back(i);
        sieve[i]=primes.size();
        for(int j=i*i;j<1000006;j+=i)sieve[j]=primes.size();
    }
    //cerr<<"ok"<<endl;
    //cerr<<"primes:";for(auto i:primes)cerr<<i<<",";cerr<<endl;

    for(int i=n-k+1;i<=n;i++)v.push_back(i);
    cnt.resize(primes.size());
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;
    for(int _=0;_<primes.size();_++){
        int p=primes[_];
        int i=(p-(n-k+1)%p)%p;

        for(;i<v.size();i+=p){
            while(v[i]%p==0){
                cnt[_]++;
                v[i]/=p;
            }
        }
        //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;
    }
    //cerr<<"ok"<<endl;
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;
    for(int i:v)if(i!=1)cnt.push_back(1);
    for(int i=1;i<=k;i++){
        int x=i;
        while(x>1){
            cnt[sieve[x]-1]--;
            x/=primes[sieve[x]-1];
        }
    }
    //cerr<<"ok"<<endl;

    int ans=1;
    for(int i:cnt)ans=(ans*(i+1))%MOD;
    //cerr<<"ok"<<endl;
    //cerr<<accumulate(cnt.begin(),cnt.end(),int(0))<<endl;
    //cerr<<"cnt:";for(auto i:cnt)cerr<<i<<",";cerr<<endl;
    //cerr<<"primes:";for(auto i:primes)cerr<<i<<",";cerr<<endl;

    cout<<ans<<endl;
}  
