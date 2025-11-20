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
        child[node] = newNode();
        newNode(); 
    }
    int query(int ql, int qr, int l, int r, int node){
        if(r < ql || qr < l || st[node] == 0)return 0;
        if(ql <= l && r <= qr)return st[node];
        int m=(l+r)/2;
        return  query(ql, qr, l,   m, child[node]  ) +
                query(ql, qr, m+1, r, child[node]+1);
    }
    void update(int x, int val, int l, int r, int node){
        if(r < x || x < l)return;
        st[node] += val;
        if(l == r)return;
        if(child[node] == -1)createChild(node);
        int m=(l+r)/2;
        update(x, val, l,   m, child[node]  );
        update(x, val, m+1, r, child[node]+1);
    }
};
///////////////////////////////////////////////////////////
mt19937 mt;

template <typename T>
struct mset{
    priority_queue<T> in,out;
    void insert(const T& x){
        in.push(x);
    }
    void erase(const T& x){
        out.push(x);
    }
    void balance(){
        while(in.size() && out.size() && in.top()==out.top()){
            in.pop();
            out.pop();
        }
    }
    T top(){
        balance();
        return in.top();
    }
};

vector<int> p;
int n;

inline chrono::milliseconds test_mset(int n){
    vector<int> v(n);
    iota(v.begin(),v.end(),0);

    auto start = chrono::high_resolution_clock::now();
    
    // your code here
    return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);

}

signed main(void){
    
}
