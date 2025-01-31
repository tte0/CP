// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m,q,x,y,first[N],last[N];

struct Segtree{
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc ((node<<1)|1)
    int* st;
    Segtree(int n){
        st==new int[4*n+5];
    }
    inline void push(int l,int r,int node){
        if(l==r || st[node]==-1)return;
        st[lc]=st[node];
        st[rc]=st[node];
        st[node]=-1;
    }
    inline void update(int x,int y,int task,int l=1,int r=n,int node=1){
        if(r<x || y<l)return;
        if(x<=l && r<=y){
            st[node]=task;
            return;
        }
        push(l,r,node);
        update(x,y,task,l,m,lc);
        update(x,y,task,m+1,r,rc);
    }
    inline int query(int x,int l=1,int r=n,int node=1){
        if(l==r)return st[node];
        push(l,r,node);
        if(x<=m)query(x,l,m,lc);
        else query(x,m+1,r,rc);
    }
    #undef m
    #undef lc
    #undef rc
};

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>q;
    for(int i=0;i<m;i++)cin>>first[i]>>last[i];

    Segtree st(n);
    for(int i=0;i<n;i++){
        int l=first[i],r=last[i];

        if(l>1){
            int task=st.query(l-1);
            if(task!=-1)last[task]=l-1;
        }
        for(int p=l;p<=r;){
            int task=st.query(p);
            
        }

        st.update(l,r,i,r);
    }
}
