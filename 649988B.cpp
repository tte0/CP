// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1.5e5+5;
struct segtree{
    vector<int> st,lazy,child;
    segtree(){
        newNode();
    }
    int newNode(){
        st.push_back(0);
        lazy.push_back(0);
        child.push_back(-1);
        return st.size()-1;
    }
    void addChild(int node){
        child[node]=newNode();
        newNode();
    }
    void push(int l,int r,int node){
        st[node]
    }
    void update(int ql,int qr,int l,int r,int node){
        if(r<ql || qr<l)return;
        if(ql<=l && r<=qr){
            lazy[node]++;
            push(l,r,node);
        }
    }
};
///////////////////////////////////////////////////////////
int n;
vector<tuple<int,int>> v;

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& [a,b]:v)cin>>a>>b;
    
    sort(v.begin(),v.end());


}
