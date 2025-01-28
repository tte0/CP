// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,ans,cnt[N],first[N];
vector<int> v,divisor[N];

struct segtree{
    #define m ((l+r)>>1)
    #define lc (node<<1)
    #define rc ((node<<1)|1)
    struct Node{
    int min=0;
    int min2=2e9;
    int sum=0;
    int cnt=1;
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
    void build(int l=0,int r=n-1,int node=1){
        //cerr<<">build:"<<l<<","<<r<<","<<node<<endl;
        if(l==r)return;
        build(l,m,lc);
        build(m+1,r,rc);
        combine(node);
    }
    void update(int x,int y,int val,int l=0,int r=n-1,int node=1){
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

inline void init(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisor[j].push_back(i);
        }
    }
}

signed main(void){
    init();
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    segtree st;
    for(int i=n;i--;){
        for(auto d:divisor[v[i]]){
            cnt[d]++;
            if(cnt[d]==1)first[d]=i;
            if(cnt[d]==2)st.update(0,i,d);
        }
    }

    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n-1;i++){
        ans+=st.query(i+1,n-1);
        for(auto d:divisor[v[i]]){
            cnt[d]++;
            if(cnt[d]==1)st.update(0,first[d],d);
            if(cnt[d]==2)st.update(0,n-1,d);
        }
    }

    memset(cnt,0,sizeof(cnt));
    int mx=0;
    for(int i=0;i<n-1;i++){
        for(auto d:divisor[v[i]]){
            cnt[d]++;
            if(cnt[d]==2)mx=max(mx,d);
        }
        ans+=mx;
    }

    cout<<ans<<endl;
}
