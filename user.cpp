// Author: Teoman Ata Korkmaz
#pragma GCC optimize("03,fast-math,unroll-loops,no-stack-protector")
//#pragma GCC target("tune=native,arch=native")
#include <bits/stdc++.h> 
#define int int_fast64_t
using u64 = uint64_t;
using namespace std;
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
constexpr u64 MOD=(1LL<<61)-1;
u64 mod(u64 x){
    u64 ans=(x&MOD)+(x>>61);
    if(ans>=MOD)ans-=MOD;
    return ans;
}
u64 mul(u64 a, u64 b) {
    __uint128_t result=__uint128_t(a)*b;
    return mod(u64(result >> 61) + u64(result & MOD));
}
const u64 base1=mod(mt());
const u64 base2=mod(mt());
struct identity_hash{
    __uint128_t operator()(__uint128_t x) const{
        return x;
    }
};
///////////////////////////////////////////////////////////
int q,ans,vis[500005];
unordered_map<__uint128_t,pair<vector<int>,bool>,identity_hash> mp;

signed main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    mp.max_load_factor(0.25);
    mp.reserve(2e5);

    cin>>q;
    while(q--){
        static int x;
        static string s;
        cin>>x>>s;
        if(x==1){
            u64 hash1=0;
            u64 hash2=0;
            for(auto c:s){
                hash1=mod(mul(hash1,base1)+c);
                hash2=mod(mul(hash2,base2)+c);
            }

            __uint128_t hash=(__uint128_t(hash1)<<64)|hash2;

            if(!mp[hash].second){
                for(auto i:mp[hash].first){
                    ans-=!vis[i];
                    vis[i]=1;
                }

                mp[hash].first.clear();
                mp[hash].second=true;
            }
        }
        else{
            ans++;
            u64 hash1=0;
            u64 hash2=0;
            for(auto c:s){
                hash1=mod(mul(hash1,base1)+c);
                hash2=mod(mul(hash2,base2)+c);
                __uint128_t hash=(__uint128_t(hash1)<<64)|hash2;
                if(mp[hash].second){
                    ans--;
                    break;
                }
                mp[hash].first.push_back(q);
            }
        }

        cout<<ans<<endl;
    }
}
