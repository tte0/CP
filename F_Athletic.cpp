// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,d,r;
vector<int> v;

struct segtree{
    vector<int> st;
    segtree(int n){
        st.assign(2*n,0);
    }
    int query(int l,int r){//[l,r)
        int ans=INT32_MIN;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans=max(ans,st[l++]);
            if(r&1)ans=max(ans,st[--r]);
        }
        return ans;
    }
    void update(int x,int val){
        for(st[x+=n]=val;x>1;x>>=1){
            st[x>>1]=max(st[x],st[x^1]);
        }
    }
};


signed main(void){
    cin>>n>>d>>r;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<tuple<int,int>> arr;
    for(int i=0;i<n;i++)arr.push_back({v[i],i});
    sort(arr.begin(),arr.end());

    segtree st(n);
    queue<pair<int,int>> q;
    for(auto [ignore,i]:arr){
        //cerr<<"i:"<<i<<endl;
        while(q.size() && v[q.front().first]<=v[i]-d){
            st.update(q.front().first,q.front().second);
            q.pop();
        }

        q.push({i,1+st.query(
            max(int(0),i-r),
            min(n-1,i+r)+1
        )});
    }

    while(q.size()){
        st.update(q.front().first,q.front().second);
        q.pop();
    }

    cout<<st.query(0,n)-1<<endl;
}
