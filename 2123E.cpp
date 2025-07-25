// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

struct segtree{
    int n;
    vector<int> st;
    segtree(int _n){
        n=1<<(32-__builtin_clz(_n-1));
        st.assign(2*n,0);
    }
    void update(int l,int r){
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)st[l++]++;
            if(r&1)st[--r]++;
        }
    }
    int query(int x){
        int ans=0;
        for(x+=n;x;x>>=1){
            ans+=st[x];
        }
        return ans;
    }
};

inline void solve(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> cnt(n+1);
    for(auto i:v)cnt[i]++;

    segtree st(n+1);
    int sum=0;
    for(int i=0;i<=n;i++){
        st.update(cnt[i],n-i+1);
        sum+=cnt[i];
        if(cnt[i]==0)break;
    }

    for(int i=0;i<=n;i++)cout<<st.query(i)<<" ";
    cout<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
