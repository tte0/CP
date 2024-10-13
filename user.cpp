#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2")
#pragma GCC optimize("unroll-loops,no-stack-protector,O3,fast-math")
#include<bits/stdc++.h>
#define int int_fast64_t
#define N 1000005
#define pb push_back
#define MOD 998244353
#define ff first
#define ss second

using namespace std;

int prime[N];
vector<int> primes,cnt;
map<int,int> mp;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    k=min(k,(n-k));
    //memset(prime,1,sizeof(prime));
    for(int i=2;i<N;i++)
    {
        //if(i<1000)
        //    cout<<prime[i];
        if(prime[i]==0)
        {
            //if(i<1000)
            //    cout<<"a";
            primes.pb(i);
            cnt.pb(0);
            for(int j=i;j<N;j+=i)
            {
                int temp=j;
                while(temp%i==0&&j<=k)
                {
                    cnt[cnt.size()-1]--;
                    temp/=i;
                }
                //if(j<=k)
                //    cout<<i<<" "<<j<<endl;
                prime[j]=1;
            }
        }
    }
    /*for(int i=2;i<=k;i++)
    {
        for(int j=0;j<primes.size();j++)
        {
            if(i==1)
                break;
            while(i%primes[j]==0)
            {
                i/=primes[j];
                cnt[j]++;
            }
        }
    }*/
    vector<int> x;
    for(int i=n-k+1;i<=n;i++)
        x.pb(i);
    for(int i=0;i<primes.size();i++)
    {
        int beg=((primes[i]-(x[0]%primes[i]))%primes[i]);
        for(int j=beg;j<x.size();j+=primes[i])
        {
            while(x[j]%primes[i]==0)
            {
                //cout<<primes[i]<<
                x[j]/=primes[i];
                cnt[i]++;
            }
        }
    }
    int ans=1;
    for(int i=0;i<x.size();i++)
        if(x[i]!=1)
            ans=(ans*2)%MOD;
    for(int i=0;i<cnt.size();i++)
    {
        //if(cnt[i]<0)
        //    continue;
        //cout<<cnt[i]<<" "<<primes[i]<<endl;
        ans=(ans%MOD*(cnt[i]+1)%MOD)%MOD;
    }
    
    cout<<ans<<endl;
    return 0;
}