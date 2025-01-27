// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
#define int int_fast64_t
using namespace std;
constexpr int N=1e6+5;
///////////////////////////////////////////////////////////
int n,q,x,y,arr[N],ans[N];
vector<int> v,comp;
vector<tuple<int,int,int>> query;

struct segtree{
    vector<int> st;
    segtree(int n){
        st.resize(2*n);
    }
    void update(int x,int val){
        for(st[x+=n]=val;x>1;x>>=1){
            st[x>>1]=st[x]^st[x^1];
        }
    }
    int query(int l,int r){
        int ans=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans^=st[l++];
            if(r&1)ans^=st[--r];
        }
        return ans;
    }
};

inline int f(int x){
    return lower_bound(comp.begin(),comp.end(),x)-comp.begin();
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    cin>>q;
    query.resize(q);
    for(int i=0;i<q;i++){
        cin>>x>>y;
        query[i]={x-1,y,i};
    }

    comp=v;
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());

    vector<int> mp(n,-1);
    segtree dis(n),sum(n);
    for(int i=0;i<n;i++){
        sum.update(i,v[i]);
        if(mp[f(v[i])]!=-1){
            arr[mp[f(v[i])]]=i;
        }
        else{
            dis.update(i,v[i]);
        }
        mp[f(v[i])]=i;
    }

    sort(query.begin(),query.end(),[](tuple<int,int,int> a,tuple<int,int,int> b){
        auto [la,ra,inda]=a;
        auto [lb,rb,indb]=b;
        return bool(la<lb);
    });

    int cur=0;
    for(auto [l,r,ind]:query){
        //cerr<<"query:"<<l<<","<<r<<","<<ind<<endl;
        while(cur<l){
            if(arr[cur]){
                assert(v[cur]==v[arr[cur]]);
                dis.update(cur,0);
                dis.update(arr[cur],v[cur]);
            }
            cur++;
        }
        ans[ind]=sum.query(l,r)^dis.query(l,r);
    }
    

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
