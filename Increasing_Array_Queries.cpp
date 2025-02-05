// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,q,x,y;
tuple<int,int> st[4*N];
vector<int> v={0};

#define m ((l+r)>>1)
#define lc (node<<1)
#define rc ((node<<1)|1)
inline void build(int l=1,int r=n,int node=1){
    
}

inline tuple<int,int> query(int l=1,int r=n,int node=1){
    
}
#undef m
#undef lc
#undef rc

signed main(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    build();
    while(q--){
        cin>>x>>y;
        auto ans=query();
    }
}
