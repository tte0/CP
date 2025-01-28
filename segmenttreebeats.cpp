// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,q,x,y,w;
vector<int> v;

struct segtree{
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc ((node<<1)|1)
    struct Node{
    int min=2e9;
    int min2=2e9;
    int sum=0;
    int cnt=1;
    int lazy=0;
    };
    Node* st=new Node[4*N];
    segtree(){
        build();
    }
    void combine(int node){
        if(st[lc].min<st[rc].min){
            st[node].min2=min(st[lc].min,st[rc].min2);
            st[node].cnt=st[rc].cnt;
        }
        else if(st[lc].min>st[rc].min){
            st[node].min2=min(st[lc].min2,st[rc].min);
            st[node].cnt=st[lc].cnt;
        }
        else{
            st[node].min2=min(st[lc].min2,st[rc].min2);
            st[node].cnt=st[lc].cnt+st[rc].cnt;
        }
        st[node].min=min(st[lc].min,st[rc].min);
        st[node].sum=st[lc].sum+st[rc].sum;
    }
    void push_min(int val,int node){
        if(val<=st[node].min)return;
        st[node].sum+=(val-st[node].min)*st[node].cnt;
        st[node].min=val;
    }
    void push(int l,int r,int node){
        if(l==r)return;
        push_min(st[node].min,lc);
        push_min(st[node].min,rc);
    }
    void build(int l=1,int r=n,int node=1){
        //cerr<<">build:"<<l<<","<<r<<","<<node<<endl;
        if(l==r){
            st[node].sum=v[l-1];
            st[node].min=v[l-1];
            return;
        }
        build(l,m,lc);
        build(m+1,r,rc);
        combine(node);
    }
    void update(int x,int y,int val,int l=1,int r=n,int node=1){
        if(r<x || y<l || val<=st[node].min)return;
        if(x<=l && r<=y && val<st[node].min2){
            push_min(val,node);
            return;
        }
        push(l,r,node);
        update(x,y,val,l,m,lc);
        update(x,y,val,m+1,r,rc);
        combine(node);
    }
    int query(int x,int y,int l=1,int r=n,int node=1){
        if(r<x || y<l)return 0;
        //cerr<<">query:"<<x<<","<<y<<"|"<<l<<","<<r<<","<<node<<endl;
        if(x<=l && r<=y)return st[node].sum;
        push(l,r,node);
        return query(x,y,l,m,lc)+query(x,y,m+1,r,rc);
    }
    #undef m
    #undef lc
    #undef rc
};

signed main(void){
    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;

    segtree st;
    while(q--){
        cin>>x;
        if(x==1){//update
            cin>>x>>y>>w;
            st.update(x,y,w);
        }
        else{//query
            cin>>x>>y;
            cout<<st.query(x,y)<<endl;
        }
    }
}
