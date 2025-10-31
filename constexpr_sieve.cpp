// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#pragma GCC target("avx2,popcnt")
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
constexpr size_t N=(((4e5+5)+29)/30); //must be a multiple of 30
constexpr char wheel_lookup[30]={-1, 0,-1,-1,-1,-1,-1, 1,-1,-1,
                                 -1, 2,-1, 3,-1,-1,-1, 4,-1, 5,
                                 -1,-1,-1, 6,-1,-1,-1,-1,-1, 7};
constexpr inline auto get_sieve(){
    // 8 bit-packed with 30-wheel : {1,7,11,13,17,19,23,29}
    // if bit==0 then prime else composite
    array<unsigned char,N> sieve{};// all-zero init
    sieve[0]=1;// 1 is not prime
    
    // 2,3,5 already processed with wheel
    for(int i=7;i*i<N*30;i+=2){
        // check whether its in wheel AND is not marked as composite
        if(wheel_lookup[i%30]!=-1)continue;
        if(!(sieve[i/30]&(char(1)<<wheel_lookup[i%30]))){
            // couldnt find smarter loop for "j", regular twice the prime increment
            for(int j=i*i;j<N*30;j+=2*i){
                //check if its in wheel
                if(wheel_lookup[j%30]==-1){
                    sieve[j/30]|=(char(1)<<wheel_lookup[j%30]);
                }
            }
        }
    }
    return sieve;
}
constexpr auto sieve=get_sieve();
constexpr inline bool isPrime(int x){
    if(x==2 || x==3 || x==5)return true;
    if(wheel_lookup[x%30]==-1)return false;
    return (sieve[x/30]&(char(1)<<wheel_lookup[x%30]));
}
///////////////////////////////////////////////////////////
int n;
vector<int> v;



inline void solve(){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
}

signed main(void){
    for(int i=0;i<100;i++){
        cout<<i<<(isPrime(i)?" is prime":" is NOT prime")<<endl;
    }
    cout<<bitset<8>(sieve[0])<<bitset<8>(sieve[1])<<bitset<8>(sieve[2])<<endl;

    int t;
    cin>>t;
    while(t--)solve();
}
