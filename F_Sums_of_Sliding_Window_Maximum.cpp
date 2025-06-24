// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,l_cnt[N],r_cnt[N];
vector<int> v;

struct segtree{
    vector<int> st;
    int n;
    segtree(int _n){
        n=_n;
        st.resize(2*n,0);
    }
    void update(int l,int r,int val){//[l,r)
        assert(l>=0 && r<=n);
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)st[l++]+=val;
            if(r&1)st[--r]+=val;
        }
    }
    int query(int x){
        assert(x>=0 && x<n);
        int ans=0;
        for(x+=n;x;x>>=1)ans+=st[x];
        return ans;
    }
};

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    stack<pair<int,int>> _st;//mx,ind
    _st.push({INT32_MAX,-1});
    for(int i=0;i<n;i++){
        while(_st.top().first<=v[i])_st.pop();
        l_cnt[i]=i-_st.top().second-1;
        _st.push({v[i],i});
    }
    while(_st.size())_st.pop();
    _st.push({INT32_MAX,n});
    for(int i=n;i--;){
        while(v[i]>_st.top().first)_st.pop();
        r_cnt[i]=_st.top().second-i-1;
        _st.push({v[i],i});
    }

    //cerr<<"l_cnt:";for(int i=0;i<n;i++)cerr<<l_cnt[i]<<",";cerr<<endl;
    //cerr<<"r_cnt:";for(int i=0;i<n;i++)cerr<<r_cnt[i]<<",";cerr<<endl;

    segtree st(n+1);
    for(int i=0;i<n;i++){
        int mn=min(l_cnt[i],r_cnt[i]);
        int mx=max(l_cnt[i],r_cnt[i]);

        st.update(0,mn+1,v[i]);
        st.update(mx+1,mn+mx+2,-v[i]);

        //cerr<<"st:";for(int i=0;i<n+1;i++)cerr<<st.query(i)<<",";cerr<<endl;
    }

    vector<int> pref(n+1);
    for(int i=0;i<=n;i++){
        pref[i]=st.query(i);
    }
    for(int i=1;i<=n;i++)pref[i]+=pref[i-1];
    assert(pref.back()==0);
    pref.pop_back();

    for(auto i:pref)cout<<i<<endl;
}
