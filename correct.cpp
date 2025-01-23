// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=200005;
///////////////////////////////////////////////////////////
int n;
vector<int> a,h;

class Segtree{
    int st[4*N];
    public:
    inline void update(int x,int val){
        for(st[x+=n]=val;x>1;x>>=1){
            st[x>>1]=max(st[x],st[x^1]);
        }
    }
    inline int query(int l,int r){
        int ans=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans=max(ans,st[l++]);
            if(r&1)ans=max(ans,st[--r]);
        }
        return ans;
    }
};

signed main(void){
    cin>>n;
    a.resize(n);    
    h.resize(n);    
    for(auto& i:h)cin>>i;
    for(auto& i:a)cin>>i;
    for(auto& i:h)i--;

    Segtree st;
    for(int i=0;i<n;i++){
        st.update(h[i],a[i]+st.query(0,h[i]));
    }

    cout<<st.query(0,n);
}
