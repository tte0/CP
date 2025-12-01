// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=998244353;
struct segtree{
    int n;
    vector<int> st;
    segtree(int _n){
        n=_n;
        st.resize(2*n);
    }
    inline int sum(int l,int r){
        int ans=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans%MOD;
    }
    inline int operator[](int x){
        return st[x+n]%MOD;
    }
    inline void set(int x,int val){
        for(st[x+=n]=val%MOD;x>1;x>>=1){
            st[x>>1]=(st[x]+st[x^1])%MOD;
        }
    }
};
///////////////////////////////////////////////////////////
int n,q;

inline void solve(){
    cin>>n>>q;
    vector<int> lefts(n,-1);
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        y--;
        lefts[y]=max(lefts[y],x);
    }

    int last=0;
    for(int i=0;i<n;i++){
        if(lefts[i]!=-1){
            lefts[i]=max(lefts[i],last);
            last=lefts[i];
        }
    }

    segtree st(n);
    st.set(0,1);
    for(int r=1;r<n;r++){
        int l=lefts[r];
        //cerr<<l<<","<<r<<endl;
        if(l==-1){
            st.set(r,(2*st[r-1])%MOD);
        }
        else{
            st.set(r,st.sum(l-1,r));
        }
    }

    //cerr<<"st: ";for(int i=0;i<n;i++)cerr<<st[i]<<",";cerr<<endl;

    cout<<(2*st[n-1])%MOD<<endl;
    //cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
