// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,ans,nxt[N];
vector<int> v,arr;

struct segtree{
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc ((node<<1)|1)
    struct Node{
    int max=-2e9;
    int max2=-2e9;
    int sum=0;
    int cnt=1;
    int lazy=0;
    };
    Node* st;
    segtree(int n){
        st=new Node[4*n+5];
        build();
    }
    void combine(int node){
        if(st[lc].max<st[rc].max){
            st[node].max2=max(st[lc].max,st[rc].max2);
            st[node].cnt=st[rc].cnt;
        }
        else if(st[lc].max>st[rc].max){
            st[node].max2=max(st[lc].max2,st[rc].max);
            st[node].cnt=st[lc].cnt;
        }
        else{
            st[node].max2=max(st[lc].max2,st[rc].max2);
            st[node].cnt=st[lc].cnt+st[rc].cnt;
        }
        st[node].max=max(st[lc].max,st[rc].max);
        st[node].sum=st[lc].sum+st[rc].sum;
    }
    void push_max(int val,int node){
        if(val>=st[node].max)return;
        st[node].sum-=(st[node].max-val)*st[node].cnt;
        st[node].max=val;
    }
    void push(int l,int r,int node){
        if(l==r)return;
        push_max(st[node].max,lc);
        push_max(st[node].max,rc);
    }
    void build(int l=0,int r=n-1,int node=1){
        //cerr<<">build:"<<l<<","<<r<<","<<node<<endl;
        if(l==r){
            st[node].sum=arr[l];
            st[node].max=arr[l];
            return;
        }
        build(l,m,lc);
        build(m+1,r,rc);
        combine(node);
    }
    void update(int x,int y,int val,int l=0,int r=n-1,int node=1){
        //cerr<<">update:"<<x<<","<<y<<","<<val<<"|"<<l<<","<<r<<","<<node<<endl;
        if(r<x || y<l || val>=st[node].max)return;
        if(x<=l && r<=y && val>st[node].max2){
            push_max(val,node);
            return;
        }
        push(l,r,node);
        update(x,y,val,l,m,lc);
        update(x,y,val,m+1,r,rc);
        combine(node);
    }
    int query(int x,int y,int l=0,int r=n-1,int node=1){
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

inline void findmex(){
    vector<int> cnt(n+5,0);
    int mex=0;
    for(int i=0;i<n;i++){
        if(v[i]<n+5)cnt[v[i]]++;
        while(cnt[mex])mex++;
        arr.push_back(mex);
    }
}

inline void findnext(){
    map<int,int> mp;
    for(int i=0;i<n;i++)nxt[i]=n;
    for(int i=0;i<n;i++){
        if(mp.find(v[i])!=mp.end())nxt[mp[v[i]]]=i;
        mp[v[i]]=i;
    }
}

inline void debugst(segtree& st){
    cerr<<"st:";for(int i=0;i<n;i++)cerr<<st.query(i,i)<<",";cerr<<endl;
}

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    findmex();
    //cerr<<"arr:";for(auto i:arr)cerr<<i<<",";cerr<<endl;

    findnext();
    //cerr<<"nxt:";for(int i=0;i<n;i++)cerr<<nxt[i]<<",";cerr<<endl;

    segtree st(n);
    for(int i=0;i<n;i++){
        ans+=st.query(i,n-1);
        if(v[i]<n)st.update(i,nxt[i]-1,v[i]);
        //cerr<<ans<<endl;
        //debugst(st);
    }

    cout<<ans<<endl;
}
