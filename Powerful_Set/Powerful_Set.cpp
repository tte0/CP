// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int n=2e5+5;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int q,st[4*n],lazy[4*n];

inline int range_sum(int l,int r){
    return (r*(r+1)-l*(l-1))/2;
}

struct segtree{
    segtree(){
        for(int i=1;i<=n;i++)set(i,i,1,n,1);
    }
    #define m ((l+r)>>1)
    #define lc ((node<<1))
    #define rc ((node<<1)|1)
    void push(int l,int r,int node){
        st[node]+=2*lazy[node]*range_sum(l,r);
        st[node]%=MOD;
        if(l<r){
            lazy[lc]+=lazy[node];
            lazy[rc]+=lazy[node];
        }
        lazy[node]=0;
    }
    void set(int i,int x,int l,int r,int node){
        if(r<i || i<l)return;
        if(l==r){
            st[node]=x;
            return;
        }
        set(i,x,l,m,lc);
        set(i,x,m+1,r,rc);
        st[node]=(st[lc]+st[rc])%MOD;
    }
    void update(int x,int y,int l,int r,int node){
        if(r<x || y<l)return;
        if(x<=l && r<=y){
            lazy[node]++;
            push(l,r,node);
            return;
        }
        push(l,r,node);
        update(x,y,l,m,lc);
        update(x,y,m+1,r,rc);
        st[node]=(st[lc]+st[rc])%MOD;
    }
    int query(int x,int y,int l,int r,int node){
        push(l,r,node);
        if(r<x || y<l)return 0;
        if(x<=l && r<=y)return st[node];
        return (query(x,y,l,m,lc)+query(x,y,m+1,r,rc))%MOD;
    }
    #undef m
    #undef lc
    #undef rc
};

signed main(void){
    cin>>q;
    int ans=0;
    segtree st;
    //cerr<<"st:";for(int i=1;i<=10;i++)cerr<<st.query(i,i,1,n,1)<<",";cerr<<"...\n";
    while(q--){
        int x,y;
        cin>>x>>y;
        ans+=st.query(x,y,1,n,1);
        ans%=MOD;
        cout<<ans<<endl;
        st.update(x,y,1,n,1);

        //cerr<<"st:";for(int i=1;i<=10;i++)cerr<<st.query(i,i,1,n,1)<<",";cerr<<"...\n";
    }
}
