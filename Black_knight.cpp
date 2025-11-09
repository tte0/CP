// Author: Teoman Ata Korkmaz
#pragma GCC optimize ("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#pragma GCC target("avx2,bmi,bmi2,popcnt")
#define int int_fast64_t
using namespace std;
constexpr int MOD=1e9+7;
struct mt{
    array<array<int,16>,16> arr{};
    constexpr mt operator+(const mt& other){
        mt ans{};
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                ans.arr[i][j]=arr[i][j]+other.arr[i][j];
            }
        }
        return ans;
    }
    constexpr mt operator*(const mt& other){
        mt ans{};
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                for(int k=0;k<16;k++){
                    ans.arr[i][j]+=arr[i][k]*other.arr[k][j];
                }
                ans.arr[i][j]%=MOD;
            }
        }
        return ans;
    }
};
constexpr mt transition({
    /*
    i->i+1   i->i+2
    i+1->i+1 i+1->i+2
    */
    0,0,0,0,0,0,0,0, 0,1,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0, 1,0,1,0,0,0,0,0,
    0,0,0,0,0,0,0,0, 0,1,0,1,0,0,0,0,
    0,0,0,0,0,0,0,0, 0,0,1,0,1,0,0,0,
    0,0,0,0,0,0,0,0, 0,0,0,1,0,1,0,0,
    0,0,0,0,0,0,0,0, 0,0,0,0,1,0,1,0,
    0,0,0,0,0,0,0,0, 0,0,0,0,0,1,0,1,
    0,0,0,0,0,0,0,0, 0,0,0,0,0,0,1,0,
    
    1,0,0,0,0,0,0,0, 0,0,1,0,0,0,0,0,
    0,1,0,0,0,0,0,0, 0,0,0,1,0,0,0,0,
    0,0,1,0,0,0,0,0, 1,0,0,0,1,0,0,0,
    0,0,0,1,0,0,0,0, 0,1,0,0,0,1,0,0,
    0,0,0,0,1,0,0,0, 0,0,1,0,0,0,1,0,
    0,0,0,0,0,1,0,0, 0,0,0,1,0,0,0,1,
    0,0,0,0,0,0,1,0, 0,0,0,0,1,0,0,0,
    0,0,0,0,0,0,0,1, 0,0,0,0,0,1,0,0,
});
constexpr auto get_bp(){
    array<mt,64> bp{};
    bp[0]=transition;
    for(int i=1;i<64;i++){
        bp[i]=bp[i-1]*bp[i-1];
    }
    return bp;
}
const array<mt,64> bp=get_bp();
constexpr inline mt fp(int b){
    mt ans{};
    for(int i=0;i<16;i++)ans.arr[i][i]=1;
    for(int i=0;i<64;i++){
        if(b&1)ans=ans*bp[i];
        b>>=1;
    }
    return ans;
}
///////////////////////////////////////////////////////////
int n,k,r;
vector<tuple<int,int>> knight,bishop;
vector<pair<int,vector<int>>> squares;

inline auto ith_square(int x){
    return lower_bound(squares.begin(),)
}

signed main(void){
    mt a=fp(1);

    for(int i=0;i<16;i++){
        if(i==8)cerr<<endl;
        for(int j=0;j<16;j++){
            if(j==8)cerr<<" ";
            cerr<<a.arr[i][j]<<",";
        }
        cerr<<endl;
    }

    cin>>n>>k;
    for(int i=0;i<n;i++){
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='B'){
            bishop.push_back({x,y});
        }
        if(c=='K'){
            knight.push_back({x,y});
        }
    }
    cin>>r;


}
