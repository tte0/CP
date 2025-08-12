// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int uint32_t
using namespace std;
constexpr int n=1e9+5;
constexpr int MOD=1e9+7;
constexpr int SIZE=2e7;
///////////////////////////////////////////////////////////
int q,st[SIZE],lazy[SIZE],child[SIZE],cnt;

inline int64_t sum(int64_t a,int64_t b){
    return (a+b)%MOD;
}

inline int64_t mul(int64_t a,int64_t b){
    return (a*b)%MOD;
}

inline int64_t range_sum(int64_t l,int64_t r){
    return (r*(r+1)-l*(l-1))/2;
}

struct segtree{
    segtree(){
        st[1]=range_sum(1,n)%MOD;
    }
    #define m ((l+r)>>1)
    void push(int l,int r,int node){
        st[node]+=mul(2,mul((lazy[node])%MOD,(range_sum(l,r))%MOD)%MOD);
        st[node]%=MOD;
        if(l<r){
            if(!child[node]){
                child[node]=2*(++cnt);
                st[child[node]]=range_sum(l,m)%MOD;
                st[child[node]|1]=range_sum(m+1,r)%MOD;
            }
            lazy[child[node]]+=lazy[node];
            lazy[child[node]|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    void update(int x,int y,int l,int r,int node){
        if(r<x || y<l)return;
        if(x<=l && r<=y){
            lazy[node]++;
            push(l,r,node);
            return;
        }
        push(l,r,node);
        update(x,y,l,m,child[node]);
        update(x,y,m+1,r,child[node]|1);
        st[node]=sum(st[child[node]],st[child[node]|1]);
    }
    int query(int x,int y,int l,int r,int node){
        push(l,r,node);
        if(r<x || y<l)return 0;
        if(x<=l && r<=y)return st[node];
        return sum(query(x,y,l,m,child[node]),query(x,y,m+1,r,child[node]|1));
    }
    #undef m
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
