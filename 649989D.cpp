// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=4e5+5;
struct segtree{
    vector<int> st;
    vector<int> child;
    segtree(){
        newNode();
    }
    int newNode(){
        st.push_back(0);
        child.push_back(-1);
        return st.size()-1;
    }
    void createChild(int node){
        child[node]=newNode();
        newNode();
    }
    int query(int ql,int qr,int l,int r,int node){
        //cerr<<"query: "<<ql<<","<<qr<<" "<<l<<","<<r<<","<<node<<" -- "<<st[node]<<endl;
        if(r<ql || qr<l || st[node]==0)return 0;
        if(ql<=l && r<=qr)return st[node];
        assert(child[node]!=-1);
        return  query(ql,qr,l,(l+r)/2,child[node]) +
                query(ql,qr,(l+r)/2+1,r,child[node]+1);
    }
    void update(int x,int val,int l,int r,int node){
        if(r<x || x<l)return;
        st[node]+=val;
        if(l==r)return;
        if(child[node]==-1)createChild(node);
        update(x,val,l,(l+r)/2,child[node]);
        update(x,val,(l+r)/2+1,r,child[node]+1);
    }
};
///////////////////////////////////////////////////////////
int n,p,ans[N];
vector<int> v;

inline void solvemin(){
    vector<int> t(n);
    iota(t.begin(),t.end(),0);

    auto costl=[&](int i){return v[i]+i;};
    auto costr=[&](int i){return v[i]+n-i;};

    sort(t.begin(),t.end(),[&](const int& a,const int& b){
        return costl(a)<costl(b);
    });
    cerr<<"t: ";for(auto i:t)cerr<<i+1<<",";cerr<<endl;

    for(int i=0;i<n;i++){
        int p=i;
        while(p && costl(p-1)==costl(p))p--;
        ans[t[i]]=p;
    }

    sort(t.begin(),t.end(),[&](const int& a,const int& b){
        return costr(a)<costr(b);
    });
    cerr<<"t: ";for(auto i:t)cerr<<i+1<<",";cerr<<endl;

    for(int i=0;i<n;i++){
        int p=i;
        while(p && costr(t[p-1])==costr(t[p]))p--;
        ans[t[i]]=min(ans[t[i]],p);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<endl;
    }
}

inline void solvemax(){
    
}

signed main(void){
    cin>>n>>p;
    v.resize(n);
    for(int& i:v)cin>>i;
    
    if(p==1)solvemin();
    else solvemax();
}
