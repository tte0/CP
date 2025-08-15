// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=5e5+5;
///////////////////////////////////////////////////////////
int n,q,st[4*N],stl[4*N],str[4*N];//mx,left,right
string s;

struct segtree{
    segtree(int _n){
        for(int i=1;i<=n;i++)update(i,s[i-1],1,n,1);
    }
    #define m ((l+r)>>1)
    #define lc ((node<<1))
    #define rc ((node<<1)|1)
    void pull(int l,int r,int node){
        if(l==r)return;
        stl[node]=stl[lc]+(stl[lc]==m-l+1 && s[m-1]==s[m])*stl[rc];
        str[node]=str[rc]+(str[rc]==r-m && s[m-1]==s[m])*str[lc];
        st[node]=max({st[lc],st[rc],(s[m-1]==s[m])*(str[lc]+stl[rc])});
    }
    void update(int x,char c,int l,int r,int node){
        //cerr<<"update:"<<x<<","<<c<<"|"<<l<<","<<r<<","<<node<<endl;
        if(r<x || x<l)return;
        if(l==r){
            st[node]=stl[node]=str[node]=1;
            s[x-1]=c;
            return;
        }
        update(x,c,l,m,lc);
        update(x,c,m+1,r,rc);
        pull(l,r,node);
    }
    tuple<int,int,int,int,int> query(int ql,int qr,int l,int r,int node){
        //cerr<<"query:"<<ql<<","<<qr<<"|"<<l<<","<<r<<","<<node<<endl;
        if(r<ql || qr<l)return {-1,-1,-1,-1,-1};
        if(ql<=l && r<=qr)return {st[node],stl[node],str[node],l,r};
        auto [lc_st,lc_stl,lc_str,lc_l,lc_r]=query(ql,qr,l,m,lc);
        auto [rc_st,rc_stl,rc_str,rc_l,rc_r]=query(ql,qr,m+1,r,rc);
        if(lc_st==-1)return {rc_st,rc_stl,rc_str,rc_l,rc_r};
        if(rc_st==-1)return {lc_st,lc_stl,lc_str,lc_l,lc_r};
        return{
            max({lc_st,rc_st,(s[lc_r-1]==s[rc_l-1])*(lc_str+rc_stl)}),
            lc_stl+(lc_stl==lc_r-lc_l+1 && s[lc_r-1]==s[rc_l-1])*rc_stl,
            rc_str+(rc_str==rc_r-rc_l+1 && s[lc_r-1]==s[rc_l-1])*lc_str,
            lc_l,
            rc_r,
        };
    }
    #undef m
    #undef lc
    #undef rc
};

signed main(void){
    cin>>n>>q>>s;
    segtree st(n);
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            char c;
            cin>>x>>c;
            st.update(x,c,1,n,1);
        }
        else{
            int y;
            cin>>x>>y;
            auto [a,b,c,d,e]=st.query(x,y,1,n,1);
            cout<<a<<endl;
        }
    }
}
