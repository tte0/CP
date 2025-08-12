// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int n=1e9+5;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int q;

inline int range_sum(int l,int r){
    return (r*(r+1)-l*(l-1))/2;
}

struct Node{
    int sum,lazy;
    Node* lc=nullptr;
    Node* rc=nullptr;
    Node(int l,int r){
        sum=range_sum(l,r);
        lazy=0;
    }
};

Node* root;

struct segtree{
    segtree(){
        root=new Node(1,n);
    }
    #define m ((l+r)>>1)
    void push(int l,int r,Node* node){
        node->sum+=2*node->lazy*range_sum(l,r);
        node->sum%=MOD;
        if(l<r){
            if(node->lc==nullptr)node->lc=new Node(l,m);
            if(node->rc==nullptr)node->rc=new Node(m+1,r);  
            node->lc->lazy+=node->lazy;
            node->rc->lazy+=node->lazy;
        }
        node->lazy=0;
    }
    void set(int i,int x,int l,int r,Node* node){
        if(r<i || i<l)return;
        if(l==r){
            node->sum=x;
            return;
        }
        push(l,r,node);  
        set(i,x,l,m,node->lc);
        set(i,x,m+1,r,node->rc);
        node->sum=(node->lc->sum+node->rc->sum)%MOD;
    }
    void update(int x,int y,int l,int r,Node* node){
        if(r<x || y<l)return;
        if(x<=l && r<=y){
            node->lazy++;
            push(l,r,node);
            return;
        }
        push(l,r,node);
        update(x,y,l,m,node->lc);
        update(x,y,m+1,r,node->rc);
        node->sum=(node->lc->sum+node->rc->sum)%MOD;
    }
    int query(int x,int y,int l,int r,Node* node){
        push(l,r,node);
        if(r<x || y<l)return 0;
        if(x<=l && r<=y)return node->sum;
        return (query(x,y,l,m,node->lc)+query(x,y,m+1,r,node->rc))%MOD;
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
        ans+=st.query(x,y,1,n,root);
        ans%=MOD;
        cout<<ans<<endl;
        st.update(x,y,1,n,root);

        //cerr<<"st:";for(int i=1;i<=10;i++)cerr<<st.query(i,i,1,n,1)<<",";cerr<<"...\n";
    }
}
