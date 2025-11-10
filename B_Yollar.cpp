// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e3+3;
struct mset{
    int k=0,sum=0,vat=0;
    priority_queue<int,vector<int>,greater<int>> q;
    mset(){}
    mset(int __k){
        k=__k;
    }
    size_t size(){
        return q.size();
    }
    int top(){
        return q.top()+vat;
    }
    void insert(int x){
        q.push(x-vat);
        sum+=x;
    }
    void pop(){
        sum-=q.top()+vat;
        q.pop();
    }
    void balance(){
        while(q.size()>k){
            pop();
        }
    }
    void erdogan(int x){
        sum+=size()*x;
        vat+=x;
    }
    void swap(mset& other){
        std::swap(k,other.k);
        std::swap(sum,other.sum);
        std::swap(vat,other.vat);
        std::swap(q,other.q);
    }
    void merge(mset& other){
        if(size()<other.size())swap(other);
        while(other.size()){
            insert(other.top());
            other.pop();
        }
        balance();
    }
    void clear(int __k){
        k=__k;
        sum=0;
        vat=0;
        while(q.size())q.pop();
    }
    void debug(){
        cerr<<"k,sum,vat: "<<k<<","<<sum<<","<<vat<<endl;
        auto _q=q;
        while(_q.size()){
            cerr<<_q.top()+vat<<" ";
            _q.pop();
        }
        cerr<<endl;
    }
};
///////////////////////////////////////////////////////////
int n,k;
vector<tuple<int,int>> adj[N];
mset st[N];

inline void dfs(int node,int p=-1){
    st[node].insert(0);
    for(auto [i,c]:adj[node]){
        if(i==p)continue;
        dfs(i,node);
        st[i].erdogan(c);
        st[node].merge(st[i]);
    }
}

signed main(void){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        x--,y--;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }    

    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++){
            st[i].clear(k);
        }
        dfs(i);
        cout<<st[i].sum<<endl;
        st[i].debug();
        cerr<<endl;

    }
}
