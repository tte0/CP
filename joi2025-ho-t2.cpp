// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> a,b,v;

struct prefixsum{
    vector<int> pref;
    prefixsum(vector<int>& v){
        pref={0};
        for(auto i:v)pref.push_back(i+pref.back());
        //cerr<<"pref:";for(auto i:pref)cerr<<i<<",";cerr<<endl;
    }
    inline int query(int l,int r){//[l,r)
        if(l>r)return query(l,n)+query(0,r);
        return pref[r]-pref[l];
    }
};
struct segtree{
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc ((node<<1)|1)
    vector<int> st,lazy;
    segtree(){
        st.assign(4*n+5,0);
        lazy.assign(4*n+5,0);
        build();
    }
    inline void combine(int node){
        st[node]=max(st[lc],st[rc]);
    }
    inline void build(int l=0,int r=n-1,int node=1){
        if(l==r){
            st[node]=v[l];
            return;
        }
        build(l,m,lc);
        build(m+1,r,rc);
        combine(node);
        
    }
    inline void push(int l,int r,int node){
        if(l<r){
            lazy[lc]+=lazy[node];
            lazy[rc]+=lazy[node];
        }
        st[node]+=lazy[node];
        lazy[node]=0;
    }
    inline void updatea(int x,int y,int val,int l=0,int r=n-1,int node=1){
        push(l,r,node);
        if(r<x || y<l)return;
        if(x<=l && r<=y){
            lazy[node]+=val;
            push(l,r,node);
            return;
        }
        updatea(x,y,val,l,m,lc);
        updatea(x,y,val,m+1,r,rc);
        combine(node);
    }
    inline int query(int x,int y,int l=0,int r=n-1,int node=1){
        push(l,r,node);
        if(r<x || y<l)return -1e18;
        if(x<=l && r<=y)return st[node];
        return max(query(x,y,l,m,lc),query(x,y,m+1,r,rc));
    }
    #undef m
    #undef lc
    #undef rc
};

signed main(void){
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    prefixsum p(b);
    for(int i=0;i<n;i++)v.push_back(a[i]-p.query(0,i));
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;

    segtree st;
    int ans=1e18;
    for(int i=0;i<n;i++){
        ans=min(ans,st.st[1]+st.lazy[1]);
        st.updatea(i,i,-p.query(0,n));
        st.updatea(0,n-1,b[i]);
        //cerr<<"ans:"<<ans<<endl;
    }

    cout<<ans<<endl;
}
