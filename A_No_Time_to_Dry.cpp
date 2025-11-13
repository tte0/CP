// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=2e5+5;
struct segtree{
    int n;
    vector<int> st;
    segtree(int __n){
        n=__n;
        st.assign(2*n,0);
    }
    void update(int l,int r,int val){//[l,r)
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)st[l++]+=val;
            if(r&1)st[--r]+=val;
        }
    }
    int query(int x){//0-index
        int ans=0;
        for(x+=n;x;x>>=1)
            ans+=st[x];
        return ans;
    }
};
struct yetanothersegtree{
    int n;
    vector<int> st;
    yetanothersegtree(int __n){
        n=__n;
        st.assign(2*n,INT32_MAX/4);
    }
    void update(int x,int val){//[l,r)
        for(st[x+=n]=val;x>1;x>>=1)
            st[x>>1]=min(st[x],st[x^1]);
    }
    int query(int l,int r){//0-index
        int ans=INT32_MAX/4;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans=min(ans,st[l++]);
            if(r&1)ans=min(ans,st[--r]);
        }
        return ans;
    }
};
///////////////////////////////////////////////////////////
int n,q,wext[N],wrev[N],ans[N];
vector<int> v;
vector<tuple<int,int>> querys,qqq[N];

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>q;
    v.resize(n);
    querys.resize(q);
    for(auto& i:v)cin>>i;
    for(auto& i:v)i--;
    for(auto& [l,r]:querys)cin>>l>>r;
    for(int i=0;i<q;i++){
        auto& [l,r]=querys[i];
        qqq[--l].push_back({--r,i});
    }
    

    segtree st(n);
    yetanothersegtree stmin(n);
    vector<int> last;

    last.assign(n,-1);
    memset(wext,-1,sizeof(wext));
    memset(wrev,-1,sizeof(wrev));
    for(int i=0;i<n;i++){
        if(last[v[i]]!=-1){
            wext[last[v[i]]]=i;
            wrev[i]=last[v[i]];
        }
        last[v[i]]=i;
    }
    for(int i=0;i<n;i++)stmin.update(i,v[i]);
    for(int i=0;i<n;i++){
        if(wrev[i]==-1)st.update(i,n,1);
        if(wrev[i]!=-1 && stmin.query(wrev[i],i)<v[i])st.update(i,n,1);
    }


    /*cerr<<"wext: ";for(int i=0;i<n;i++)cerr<<wext[i]<<",";cerr<<endl;
    cerr<<"wrev: ";for(int i=0;i<n;i++)cerr<<wrev[i]<<",";cerr<<endl;
    cerr<<"last: ";for(int i=0;i<n;i++)cerr<<last[i]<<",";cerr<<endl;
    cerr<<"st: ";for(int i=0;i<n;i++)cerr<<st.query(i)<<",";cerr<<endl;
    cerr<<"stmin: ";for(int i=0;i<n;i++)cerr<<stmin.query(i,i+1)<<",";cerr<<endl;*/
    


    for(int l=0;l<n;l++){
        /*cerr<<endl<<"-- l = "<<l<<" --"<<endl;
        cerr<<"st: ";for(int i=0;i<n;i++)cerr<<st.query(i)<<",";cerr<<endl;
        cerr<<"v:  ";for(int i=0;i<n;i++)cerr<<v[i]+1<<",";cerr<<endl;*/
        for(auto [r,i]:qqq[l]){
            ans[i]=st.query(r);
        }
        st.update(l,wext[l]==-1?n:wext[l],-1);
        if(wext[l]!=-1 && stmin.query(l,wext[l])<v[l])st.update(wext[l],n,-1);
    }

    
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
}
