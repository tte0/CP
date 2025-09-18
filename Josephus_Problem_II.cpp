// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;

struct segtree{
    int n;
    vector<int> st;
    segtree(int _n){
        n=_n;
        st.resize(4*n);
        for(int i=1;i<=n;i++)set(i,1,1,n,1);
    }
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc ((node<<1)|1)
    void set(int i,int x,int l,int r,int node){
        if(r<i || i<l)return;
        if(l==r){
            st[node]=x;
            return;
        }
        set(i,x,l,m,lc);
        set(i,x,m+1,r,rc+1);
        st[node]=st[lc]+st[rc];
    }
    int query(int x,int y,int l,int r,int node){
        if(r<x || y<l)return 0;
        if(x<=l && r<=y)return st[node];
        return query(x,y,l,m,lc)+query(x,y,m+1,r,rc);
    }
    #undef m 
    #undef lc 
    #undef rc 
};

signed main(void){
}
