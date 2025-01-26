// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e5+5;
///////////////////////////////////////////////////////////
int n;
vector<int> v,ind[N];
vector<tuple<int,int>> query[N];//k,ans

struct segtree{
    #define m (l+r>>1)
    #define lc (node<<1)
    #define rc (node<<1|1)
    int st[4*N]={};
    inline void update(int x,int val,int l=1,int r=n,int node=1){
        ///cerr<<">update:"<<x<<","<<val<<"|"<<l<<","<<r<<","<<node<<endl;
        if(l==r)return void(st[node]=val);
        if(x<=m)update(x,val,l,m,lc);
        else    update(x,val,m+1,r,rc);
        st[node]=st[lc]+st[rc];
    }
    inline int query(int x,int l=1,int r=n,int node=1){
        if(l==r)return st[node]>x?l-1:l;
        if(st[lc]<=x)return query(x-st[lc],m+1,r,rc);
        else return query(x,l,m,lc);
    }
    #undef m
    #undef lc
    #undef rc
};

inline void debug(){
    cerr<<endl;
    for(int i=0;i<=n;i++){
        cerr<<"query:";
        for(auto [k,ans]:query[i])cerr<<"["<<k<<","<<ans<<"], ";
        cerr<<endl;
    }
}

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    for(int i=0;i<n;i++){
        ind[--v[i]].push_back(i);
    }

    segtree st;
    for(int i=0;i<n;i++){
        reverse(ind[i].begin(),ind[i].end());
        /*cerr<<"ind:";
        for(auto _:ind[i])cerr<<_<<" ";
        cerr<<endl;*/
        if(ind[i].size()) st.update(ind[i].back()+1,1);
    }

    for(int i=1;i<=n;i++)query[0].push_back({i,0});
    //debug();
    for(int i=0;i<n;i++){
        while(query[i].size()){
            auto [k,ans]=query[i].back();
            query[i].pop_back();
            query[st.query(k)].push_back({k,ans+1});
        }
        st.update(ind[v[i]].back()+1,0);
        ind[v[i]].pop_back();
        if(ind[v[i]].size()) st.update(ind[v[i]].back()+1,1);
        //debug();
    } 

    sort(query[n].begin(),query[n].end());
    for(auto [k,ans]:query[n]){
        cout<<ans<<" ";
    }
}
