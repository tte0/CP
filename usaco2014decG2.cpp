// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=500005;
///////////////////////////////////////////////////////////
int n,q,w,x,y,st[4*N],stm[4*N],a[N],b[N];

inline int dist(int i,int j){
    if()
}

#define m ((l+r)>>1)
inline int query(int l=1,int r=n,int node=1){
    if(r<x || y<l)return 0;
    if(x<=l && r<=y)return st[node];
    return query(l,m,node<<1)+query(m+1,r,node<<1|1);
}

inline int querym(int l=1,int r=n,int node=1){
    if(r<x || y<l)return 0;
    if(x<=l && r<=y)return stm[node];
    return max(querym(l,m,node<<1),querym(m+1,r,node<<1|1));
}

inline void update(int l=1,int r=n,int node=1){
    
}
#undef m

signed main(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        w=i,x=a[i],y=b[i];
        update();
    }

    while(q--){
        char c;
        cin>>c;
        if(c=='Q'){
            cin>>x>>y;
            int ans=query();
            x++,y--;
            if(x<=y)ans-=querym();
            cout<<ans;
        }
        else{

        }
    }
}
