// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=5e5+5;
struct segtree{
    int n;
    vector<int> st;
    segtree(int __n):n(__n){
        st.assign(2*n,INT32_MAX/4);
    }
    int query(int l,int r){//[l,r)
        int ans=st[0];
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans=min(ans,st[l++]);
            if(r&1)ans=min(ans,st[--r]);
        }    
        return ans;
    }
    void update(int x,int val){
        for(st[x+=n]=val;x>1;x>>=1){
            st[x>>1]=min(st[x],st[x^1]);
        }
    }
};
///////////////////////////////////////////////////////////
int n,q,last[N],ans[N];
vector<int> v;
vector<tuple<int,int>> query[N];

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(last,-1,sizeof(last));

    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;   
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        query[y].push_back({x,i});
    }

    vector<int> comp=v;
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    for(auto& i:v)i=lower_bound(comp.begin(),comp.end(),i)-comp.begin();

    segtree st(n);

    for(int r=0;r<n;r++){
        if(last[v[r]]!=-1)st.update(last[v[r]],r-last[v[r]]);
        last[v[r]]=r;
        for(auto [l,i]:query[r]){
            ans[i]=st.query(l,r);
        }
    }

    for(int i=0;i<q;i++)cout<<(ans[i]>=INT32_MAX/4 ? -1 : ans[i])<<endl;
}
