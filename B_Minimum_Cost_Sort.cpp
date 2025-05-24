// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,st[2*N];
vector<int> v,cnt;

inline void update(int x){
    for(st[x+=n]++;x>1;x>>=1)st[x>>1]=st[x]+st[x^1];
}

inline void query(int r,int l=0){

}

signed main(void){
    cin>>n;
    v.resize(n);
    cnt.resize(n);
    for(int& i:v)cin>>i;
    for(int& i:v)--i;

    
}
