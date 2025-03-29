// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=1e6+6;
constexpr uint64_t MOD=(1ULL<<61)-1;
///////////////////////////////////////////////////////////
inline uint64_t mul(uint64_t a, uint64_t b){
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&MOD) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & MOD) + (ret>>61);
	ret = (ret & MOD) + (ret>>61);
	return ret-1;
}

inline uint64_t fp(uint64_t b,uint64_t p){
    uint64_t ans;
    while(p){
        if(p&1)ans=mul(ans,b);
        p>>=1;
        b=mul(b,b);
    }
    return ans;
}

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<uint64_t> dist(0,MOD-1);
uint64_t base[N]={1,dist(rng)};

struct Hash{
    size_t n;
    uint64_t* hash;
    Hash(string s){
        n=s.size();
        hash=new uint64_t[n+1];

        for(int i=1;i<=n;i++){
            hash[i]=(mul(hash[i-1],base[1])+(s[i]-'a'))%MOD;
        }
    }
};

inline void init(){
    for(int i=2;i<N;i++)base[i]=mul(base[i-1],base[1]);
}

signed main(void){
    init();
}
