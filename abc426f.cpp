// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
struct segtree{
    int n;
    vector<__int128_t> st;
    vector<int> lazy,mn,mn2,cnt;
    segtree(const vector<int>& v){
        n=v.size();
        st.assign(4*n,0);
        lazy.assign(4*n,0);
        mn.assign(4*n,INT64_MAX);
        mn2.assign(4*n,INT64_MAX);
        cnt.assign(4*n,0);

        build(1,1,n,v);
    }
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc (node<<1|1)
    inline void pull(const int& node){
        if(mn[lc]<mn[rc]){
            mn2[node]=mn[rc];
            cnt[node]=cnt[lc];
        }
        else if(mn[lc]>mn[rc]){
            mn2[node]=mn[lc];
            cnt[node]=cnt[rc];
        }
        else{
            mn2[node]=mn[lc];
            cnt[node]=cnt[lc]+cnt[rc];
        }
        st[node]=st[lc]+st[rc];
        mn[node]=min(mn[lc],mn[rc]);
    }
    inline void push(const int& node,const int& l,const int& r){
        
    }
    void build(int node,int l,int r,const vector<int>& v){
        if(l==r){
            st[node]=mn[node]=v[l-1];
            return;
        }
        build(lc,l,m,v);
        build(rc,m+1,r,v);
        pull(node);
    }
    void update1(const int& ql,const int& qr,const int& x,int node,int l,int r){
        if(r<ql || qr<l)return;
        if(ql<=l && r<=qr){
            lazy[node]-=x;
        }
    }
    #undef m
    #undef lc
    #undef rc
    __int128_t query(const int& l,const int& r){

    }
    void update(const int& l,const int& r,const int& x){

    }
};
///////////////////////////////////////////////////////////
int n,q;
vector<int> v;

signed main(void){
    cin>>n;
    v.resize(n);
    for(int& i:v)cin>>i;
    
    segtree st(v);

    cin>>q;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        __int128_t ans=st.query(l,r);
        st.update(l,r,x);
        ans-=st.query(l,r);
        cout<<int(ans)<<endl;
    }
}
