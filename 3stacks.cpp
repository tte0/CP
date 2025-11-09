// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#pragma GCC target("popcnt")
#define int int_fast64_t
using namespace std;
constexpr int INF=INT64_MAX/4;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

inline void solve(){
    cin>>n;n<<=1;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> dp;
    vector<int> dp_old(1LL<<(n/2),INF);

    dp_old[0]=0;
    for(int i=0;i<n;i++){
        dp.assign(1LL<<(n/2),INF);
        //cerr<<"dp:";
        for(int b=0;b<(1LL<<(n/2));b++){
            //cerr<<dp_old[b]<<",";
            bool sfit=i>=n/2;
            //add
            if(i<n/2 || !(b&1)){
                //cerr<<"added at: "<<i<<","<<b<<" to "<<i+1<<","<<((b|(1<<(i-max(0L,i-n/2))))>>sfit)<<endl;
                dp[(b|(1<<(i-max(0L,i-n/2))))>>sfit]=min(dp[(b|(1<<(i-max(0L,i-n/2))))>>sfit],dp_old[b]);
            }
            //remove
            if(__builtin_popcountll(b)){
                //cerr<<"remove at: "<<i<<","<<b<<" to "<<i+1<<","<<((b^(1<<__builtin_ctzll(b)))>>sfit)<<endl;
                dp[(b^(1<<__builtin_ctzll(b)))>>sfit]=min(dp[(b^(1<<__builtin_ctzll(b)))>>sfit],dp_old[b]+abs(v[i]-v[__builtin_ctzll(b)+max(0L,i-n/2)]));
            }
        }
        //cerr<<endl;
        swap(dp,dp_old);
    }

    /*for(int i=0;i<n;i++){
        cerr<<"dp:";
        for(int b=0;b<(1LL<<(n/2));b++){
            cerr<<dp_old[b]<<",";
        }
        cerr<<endl;
    }*/

    cout<<dp_old[0]<<endl;
    //cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
