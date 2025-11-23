// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#pragma GCC target("avx2,bmi,bmi2,popcnt")
using namespace std;
struct treap{
    int n;
    uint32_t root;
    vector<int32_t> key;
    vector<int64_t> sum;
    vector<uint32_t> left,right,size,weight;
    vector<bool> lazy;

    inline uint32_t newNode(int x){return newNode(x,0,0,1,x);}
    inline uint32_t newNode(int x,int l,int r,int sz,int sm){
        key.push_back(x);
        sum.push_back(sm);
        left.push_back(l);
        right.push_back(r);
        size.push_back(sz);
        weight.push_back(rand());
        lazy.push_back(false);
        return key.size()-1;
    }
    
    treap(const vector<int>& v){
        n=v.size();
        key.reserve(n+1);
        sum.reserve(n+1);
        left.reserve(n+1);
        right.reserve(n+1);
        size.reserve(n+1);
        weight.reserve(n+1);
        lazy.reserve(n+1);

        newNode(0,0,0,0,0);//nullptr
        root=newNode(v[0]);
        for(int i=1;i<n;i++){
            root=merge(root,newNode(v[i]));
        }
    }

    inline void push(uint32_t node){
        assert(node);
        if(lazy[node]){
            lazy[left[node]]=!lazy[left[node]];
            lazy[right[node]]=!lazy[right[node]];
            swap(left[node],right[node]);
            lazy[node]=0;
        }
    }
    
    inline void pull(uint32_t node){
        assert(node);
        size[node]=size[left[node]]+size[right[node]]+1;
        sum[node]=sum[left[node]]+sum[right[node]]+key[node];
    }

    uint32_t merge(uint32_t l,uint32_t r){
        assert(l||r);
        if(!l)return r;
        if(!r)return l;
        if(weight[l]>weight[r]){
            push(l);
            right[l]=merge(right[l],r);
            pull(l);
            return l;
        }
        else{
            push(r);
            left[r]=merge(l,left[r]);
            pull(r);
            return r;
        }
    }

    void split(uint32_t node,uint32_t& l,uint32_t& r,int k){
        if(!node){
            l=r=0;
            return;
        }
        push(node);
        if(size[left[node]]>=k){
            split(left[node],l,left[node],k);
            r=node;
            pull(r);
        }
        else{
            split(right[node],right[node],r,k-(size[left[node]]+1));
            l=node;
            pull(l);
        }
    }

    void reverse(int ql,int qr){
        uint32_t l,m,r;
        split(root,l,r,qr);
        split(l,l,m,ql);
        lazy[m]=!lazy[m];
        root=merge(l,merge(m,r));
    }

    int64_t query(int ql,int qr){
        uint32_t l,m,r;
        split(root,l,r,qr);
        split(l,l,m,ql);
        int64_t ans=sum[m];
        root=merge(l,merge(m,r));
        return ans;
    }
};
///////////////////////////////////////////////////////////
int n,q;
vector<int> v;

signed main(void){
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;    

    treap trp(v);

    while(q--){
        int x,y;
        cin>>x;
        if(x==1){
            cin>>x>>y;
            x--;
            trp.reverse(x,y);
        }
        else{
            cin>>x>>y;
            x--;
            cout<<trp.query(x,y)<<endl;
        }
    }
}
