// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
#define mid ((l+r)>>2)
using namespace std;
constexpr int N=5e5;
///////////////////////////////////////////////////////////
int n,q,answers[N];
vector<int> v;

struct segtree{
    int st[200005],n=100000;
    segtree(){
        memset(st,0,sizeof(st));
    }

    void update(int x,int y){
        for(st[x+=n]+=y;x>1;x>>=1){
            st[x>>1]=st[x]+st[x^1];
        }
    }
    int query(int l,int r){
        int ans=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans+=st[l--];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};

inline int block(int x){
    return (x>>8)-(x>>11);
}

inline void solve(){
    cin>>n>>q;  
    v.resize(n);
    for(int& i:v)cin>>i;

    vector<tuple<int,int,int,int>> query(q);
    for(int i=0;i<q;i++){
        auto& [l,r,c,j]=query[i];j=i;
        cin>>l>>r>>c;
    }

    sort(query.begin(),query.end(),[&](tuple<int,int,int,int> a,tuple<int,int,int,int> b){
        auto [al,ar,ac,ai]=a;
        auto [bl,br,bc,bi]=b;
        if(block(al) != block(bl)) return al<bl;
        return ar<br;
    });

    int l=0,r=0;
    segtree st;st.update(v[0],1); 
    for(auto [ll,rr,c,i]:query){
        while(r<rr){
            st.update(v[++r],1);
        }
        while(ll<l){
            st.update(v[--l],1);
        }
        while(rr<r){
            st.update(v[r--],-1);
        }
        while(l<ll){
            st.update(v[l--],-1);
        }

        vector<int> divs;
        for(int i=1;i<=sqrt(c);i++){
            if(c%i==0){
                divs.push_back(i);
                divs.push_back(c/i);
            }
        }

        sort(divs.begin(),divs.end());

        int ans=st.query(c,100001);
        for(int i=0;i<divs.size()-1;i++){
            int y=c/divs[i],x=c/divs[i+1];
            ans=max(ans,st.query())
        }
    }
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

