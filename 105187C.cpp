// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,q,x,y;
vector<int> v,st[4*N];

#define m (l+r>>1)
#define lc (node<<1)
#define rc (node<<1|1)
inline void combine(vector<int> a,vector<int> b,vector<int>& x){
    int lp=0,rp=0;
    for(int i=0;i<30;i++){
        if(a[lp]>b[rp]){
            x[i]=a[lp];
            lp++;
        }
        else{
            x[i]=b[rp];
            rp++;
        }
    }
}
inline void calc(int l,int r,int node){
    st[node].assign(30,0);
    if(l==r){
        st[node][0]=v[l-1];
        return;
    }
    combine(st[lc],st[rc],st[node]);
}
inline void build(int l=1,int r=n,int node=1){
    if(l<r){
        build(l,m,lc);
        build(m+1,r,rc);
    }
    calc(l,r,node);
}
inline void update(int l=1,int r=n,int node=1){
    if(l<r){
        if(x<=m)update(l,m,lc);
        else update(m+1,r,rc);
    }
    calc(l,r,node);
}
inline vector<int> query(int l=1,int r=n,int node=1){
    assert(!(r<x || y<l));
    if(x<=l && r<=y)return st[node];
    vector<int> ans(30,0);
    if(x<=m)combine(ans,query(l,m,lc),ans);
    if(m+1<=y)combine(ans,query(m+1,r,rc),ans);
    return ans;
}
#undef m;
#undef lc;
#undef rc;

signed main(void){
    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;

    build();
    while(q--){
        cin>>x;
        if(x==0){
            cin>>x>>y;
            v[x++]=y;
            update();
        }
        else{
            cin>>x>>y;
            x++,y++;
            auto ans=query();
            int riyalans=0;
            for(int i=0;i+2<30;i++){
                if(v[i]<v[i+1]+v[i+2]){
                    riyalans=v[i]+v[i+1]+v[i+2];
                    break;
                }
            }
            cout<<riyalans<<endl;
        }
    }
}
