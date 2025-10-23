// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast32_t
using namespace std;
constexpr int N=2e5+5;
constexpr int block=450;
///////////////////////////////////////////////////////////
int n,y,v_cnt[N],cnt[N];
vector<int> v,check[N],divisors[N];

inline int d(int a,int b){
    return (a-1)/b+1;
}

inline void solve(){
    cin>>n>>y;
    v.resize(n);
    for(auto& i:v)cin>>i;

    for(int i=0;i<N;i++)check[i].clear();
    for(int i=0;i<n;i++){
        for(auto d:divisors[v[i]]){
            check[d].push_back(i);
        }
    }

    memset(v_cnt,0,sizeof(v_cnt));
    for(auto i:v)v_cnt[i]++;

    int_fast64_t ans=INT64_MIN,profit=0;
    for(int x=2;x<=block;x++){
        memset(cnt,0,sizeof(cnt));
        for(auto i:v)cnt[d(i,x)]++;

        profit=0;
        for(int i=0;i<=N/x;i++)profit+=int_fast64_t(i*cnt[i])-int_fast64_t(y)*int_fast64_t(max(cnt[i]-v_cnt[i],int(0)));

        ans=max(ans,profit);
    }

    for(int x=block+1;x<N;x++){
        for(auto i:check[x]){
            // val -> val-1
            int val=d(v[i],x-1);

            //remove d(v[i],x-1)
            if(v_cnt[val]<cnt[val])profit+=y;
            profit-=val;

            cnt[val]--;
            val--;
            cnt[val]++;

            //add d(v[i],x)
            if(v_cnt[val]<cnt[val])profit-=y;
            profit+=val;
        }

        ans=max(ans,profit);
    }

    cout<<ans<<"\n";
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }

    int t;
    cin>>t;
    while(t--)solve();    
}
