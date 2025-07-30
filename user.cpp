// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q;
vector<int> v;

struct segtree{
    int n;
    vector<int> st,stmax,stmin,lazy;
    segtree(vector<int>& v){
        n=v.size();
        st.assign(4*n,0);
        stmax.assign(4*n,0);
        stmin.assign(4*n,0);
        lazy.assign(4*n,-1);

        for(int i=0;i<n;i++)set(v[i],i+1,1,n,1);
    }
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc ((node<<1)+1)
    void push(int l,int r,int node){
        if(lazy[node]==-1)return;
        st[node]=(r-l+1)*lazy[node];
        stmax[node]=stmin[node]=lazy[node];
        if(l<r)lazy[lc]=lazy[rc]=lazy[node];
        lazy[node]=-1;
    }
    void pull(int node){
        st[node]=st[lc]+st[rc];
        stmax[node]=max(stmax[lc],stmax[rc]);
        stmin[node]=min(stmin[lc],stmin[rc]);
    }
    void set(int x,int i,int l,int r,int node){
        if(r<i || i<l) return;
        if(l==r){
            st[node]=stmax[node]=stmin[node]=x;
            lazy[node]=-1;
            return;
        }
        push(l,r,node);
        set(x,i,l,m,lc);
        set(x,i,m+1,r,rc);
        pull(node);
    }
    void mod(int ql,int qr,int x,int l,int r,int node){
        if(r<ql || qr<l || stmax[node]<x)return;
        if(ql<=l && r<=qr && stmax[node]==stmin[node]){
            lazy[node]=stmax[node]%x;
            push(l,r,node);
            return;
        }
        push(l,r,node);
        mod(ql,qr,x,l,m,lc);
        mod(ql,qr,x,m+1,r,rc);
        pull(node);
    }
    int query(int ql,int qr,int l,int r,int node){
        push(l,r,node);
        if(r<ql || qr<l)return 0;
        if(ql<=l && r<=qr)return st[node];
        return query(ql,qr,l,m,lc)+query(ql,qr,m+1,r,rc);
    }
    #undef m
    #undef lc
    #undef rc
};

signed main(void){
    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    segtree st(v);

    while(q--){
        int x,y,z;
        cin>>x;
        if(x==1){
            cin>>x>>y;
            cout<<st.query(x,y,1,n,1)<<endl;
        }
        else if(x==2){
            cin>>x>>y>>z;
            st.mod(x,y,z,1,n,1);
        }
        else{
            cin>>x>>y;
            st.set(y,x,1,n,1);
        }
    }

    //for(int i=1;i<=n;i++)cerr<<st.query(i,i,1,n,1);
}
