// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m,q,ans[N];
vector<pair<int,int>> v,query;
vector<tuple<int,int,int>> arr,arr2;//place,type,ind

struct segtree{
    int n;
    vector<int> st;
    segtree(int _n){
        n=_n;
        clear();
    }
    void update(int x){
        //cerr<<"update:"<<x<<endl;
        for(st[x+=n]++;x>1;x>>=1){
            st[x>>1]=st[x]+st[x^1];
        }
    }
    int query(int l,int r){//[l,r)
        //cerr<<"query:"<<l<<","<<r<<endl;
        int ans=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
    void clear(){
        st.assign(2*n,0);
    }
};

signed main(void){
    cin>>m>>n;
    v.resize(n);
    for(auto& [a,b]:v)cin>>a>>b;
    cin>>q;
    query.resize(q);
    for(auto& [a,b]:query)cin>>a>>b;

    for(int i=0;i<n;i++){
        auto [l,r]=v[i];
        arr.push_back({l,0,i});
        arr2.push_back({r,0,i});
    }
    for(int i=0;i<q;i++){
        auto [l,r]=query[i];
        arr.push_back({l,1,i});
        arr2.push_back({r,1,i});
    }

    sort(arr.begin(),arr.end());
    sort(arr2.rbegin(),arr2.rend());

    segtree st(2e6+6);
    for(size_t i=0;i<arr.size();i++){
        auto [x,type,ind]=arr[i];
        if(type==0){
            st.update(v[ind].second);
        }
        else if(type==1){
            ans[ind]+=st.query(query[ind].first,query[ind].second+1);
        }
    }
    st.clear();
    for(size_t i=0;i<arr.size();i++){
        auto [x,type,ind]=arr2[i];
        if(type==0){
            st.update(v[ind].first);
        }
        else if(type==1){
            ans[ind]+=st.query(query[ind].first,query[ind].second+1);
        }
    }

    for(int i=0;i<q;i++)cout<<ans[i]<<endl;
}
