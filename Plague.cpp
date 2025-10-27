// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,q;
vector<int> v;

struct segtree{
    int n,st[2*N];
    segtree(int _n):n(_n){}
    void update(int x,int val){
        for(st[x+=n]=val;x>1;x>>=1)
            st[x>>1]=max(st[x],st[x^1]);
    }
    int query(int l,int r){
        int ans=-1;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans=max(ans,st[l++]);
            if(r&1)ans=max(ans,st[--r]);
        }
        return ans;
    }
};

signed main(void){
    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;

    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    v.insert(v.begin(),INT64_MIN/4);
    v.push_back(INT64_MAX/4);
    n=v.size();

    segtree st(n);
    for(int i=0;i<n-1;i++){
        st.update(i,(v[i+1]-v[i])/2);
    }


    while(q--){
        int x,y;
        cin>>x>>y;

        int pl=lower_bound(v.begin(),v.end(),x)-v.begin();
        int pr=upper_bound(v.begin(),v.end(),y)-v.begin()-1;

        if(pl>pr){
            swap(pl,pr);
            cout<<min({
                abs(v[pl]-y),
                abs(v[pr]-x),
                abs((v[pr]-v[pl])/2)
            })<<endl;
            continue;
        }

        cout<<min(
            max({
                st.query(pl,pr),
                min(abs(v[pl]-x),abs((v[pl]-v[pl-1])/2)),
                min(abs(v[pr]-y),abs((v[pr+1]-v[pr])/2)),
            }),
            (v[pr+1]-v[pl-1])/2
        )<<endl;

        cerr<<endl;
    }
}
