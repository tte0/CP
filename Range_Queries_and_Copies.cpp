// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#pragma GCC target("avx2,bmi,bmi2,popcnt")
using namespace std;
struct segtree{
    int n;
    vector<int64_t> st;
    vector<size_t> left,right,root;
    
    size_t newNode(int val){
        st.push_back(val);
        left.push_back(-1);
        right.push_back(-1);
        return st.size()-1;
    }
    size_t newNode(int l,int r){
        st.push_back(st[l]+st[r]);
        left.push_back(l);
        right.push_back(r);
        return st.size()-1;
    }
    size_t newNode(size_t node){
        st.push_back(st[node]);
        left.push_back(left[node]);
        right.push_back(right[node]);
        return st.size()-1;
    }

    segtree(const vector<int>& v,int query_hint=0){
        n=v.size();
        st.reserve(4*n+query_hint*(__lg(n)+2));
        left.reserve(4*n+query_hint*(__lg(n)+2));
        right.reserve(4*n+query_hint*(__lg(n)+2));
        root.reserve(query_hint);
        root.push_back(build(1,n,v));
    }

    #define mid ((l+r)>>1)
    
    inline size_t build(int l,int r,const vector<int>& v){
        if(l==r)return newNode(v[l-1]);
        return newNode(build(l,mid,v),build(mid+1,r,v));
    }
    
    inline size_t update(int node,int l,int r,int qx,int qy){
        if(l==r)   return newNode(qy);
        if(qx<=mid)return newNode(update(left[node],l,mid,qx,qy),right[node]);
        else       return newNode(left[node],update(right[node],mid+1,r,qx,qy));
    }
    
    inline int64_t query(int node,int l,int r,int ql,int qr){
        if(r<ql || qr<l)return 0;
        if(ql<=l && r<=qr)return st[node];
        return query(left[node],l,mid,ql,qr)+query(right[node],mid+1,r,ql,qr);
    }
    #undef mid

    int64_t query(int k,int ql,int qr){
        return query(root[k],1,n,ql,qr);
    }

    void update(int k,int qx,int qy){
        root[k]=update(newNode(root[k]),1,n,qx,qy);
    }

    void copy(int k){
        root.push_back(newNode(root[k]));
    }
};
///////////////////////////////////////////////////////////
int n,q,cnt;
vector<int> v;

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    segtree st(v,q);

    while(q--){
        int x,a,b,k;
        cin>>x>>k;k--;
        if(x==1){
            cin>>a>>x;
            st.update(k,a,x);
        }
        else if(x==2){
            cin>>a>>b;
            cout<<st.query(k,a,b)<<endl;
        }
        else{
            st.copy(k);
        }
    }
}
