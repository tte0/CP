// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q,x,y,st[1<<20][2];
string s;
vector<int> v;

#define m ((l+r)>>1)
#define lc (node<<1)
#define rc ((node<<1)|1)
inline void combine(int l,int r,int node){
    if(l==r){
        st[node][v[l-1]]=1;
        st[node][v[l-1]^1]=0;
        return;
    }
    st[node][1]=st[lc][1];
    st[node][0]=st[rc][0];
    if(st[lc][0]>st[rc][1])st[node][0]+=st[lc][0]-st[rc][1];
    if(st[lc][0]<st[rc][1])st[node][1]+=st[rc][1]-st[lc][0];
}

inline void build(int l=1,int r=n,int node=1){
    if(l<r){
        build(l,m,lc);
        build(m+1,r,rc);
    }
    combine(l,r,node);
}

inline void update(int l=1,int r=n,int node=1){
    if(r<x || x<l)return;
    if(l<r){
        update(l,m,lc);
        update(m+1,r,rc);
    }
    combine(l,r,node);
}

inline pair<int,int> query(int l=1,int r=n,int node=1){
    if(r<x || y<l)return {0,0};
    if(x<=l && r<=y)return {st[node][1],st[node][0]};
    auto a=query(l,m,lc);
    auto b=query(m+1,r,rc);
    if(a.second>b.first)b.second+=a.second-b.first;
    if(a.second<b.first)a.first+=b.first-a.second;
    return {a.first,b.second};
}
#undef m
#undef lc
#undef rc

signed main(void){
    cin>>s>>q;
    n=s.size();
    for(int i=0;i<n;i++)v.push_back(s[i]-'0');

    build();
    while(q--){
        cin>>x;
        if(x==1){
            cin>>x;
            v[x-1]^=1;
            update();
        }
        else{
            cin>>x>>y;
            auto ans=query();
            cout<<ans.first+ans.second<<endl;
        }
    }
}
