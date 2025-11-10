// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
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
int n,q;
vector<int> v;

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    int a=1e9;
    segtree st;
    for(auto i:v)st.update(i,1,1,a,0);

    cin>>q;    
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int k,s;
            cin>>k>>s;
            st.update(v[k-1],-1,1,a,0);
            st.update(s,1,1,a,0);
            v[k-1]=s;
        }
        else{
            int x,y,l,r;
            cin>>x>>y>>l>>r;
            cout<<st.query((x-1)/r+1,y/l,1,a,0)<<endl;
            //cerr<<endl;
        }
    }
}
