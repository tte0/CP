// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
#define m ((l+r)>>1)
#define lc (node<<1)
#define rc ((node<<1)|1)
using namespace std;
constexpr int N=1<<18;
///////////////////////////////////////////////////////////
int n,q,x,st[4*N][3][2];//ind,l-mid-r,0,1
vector<int> v;
string s;

inline void calc(int l,int r,int node){
    if(l==r){
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                st[node][i][j]=1-(j^v[l-1]);
            }
        }
        return;
    }

    for(int b=0;b<2;b++){
        st[node][0][b]=st[lc][0][b];
        st[node][2][b]=st[rc][2][b];
        st[node][1][b]=max({st[lc][1][b],st[rc][1][b],st[lc][2][b]+st[rc][0][b]});
        if(st[lc][0][b]==m-l+1)st[node][0][b]+=st[rc][0][b];
        if(st[rc][2][b]==r-m  )st[node][2][b]+=st[lc][2][b];
    }
}

inline void build(int l=1,int r=n,int node=1){
    //cerr<<"build:"<<l<<","<<r<<","<<node<<endl;
    if(l<r){
        build(l,m,lc);
        build(m+1,r,rc);
    }
    calc(l,r,node);
}

inline void update(int l=1,int r=n,int node=1){
    //cerr<<"update:"<<l<<","<<r<<","<<node<<endl;
    if(r<x || x<l)return;
    if(l<r){
        if(x<=m)update(l,m,lc);
        else update(m+1,r,rc);
    }
    calc(l,r,node);
}

inline int query(){
    return max(st[1][1][0],st[1][1][1]);
}

signed main(void){
    cin>>s>>q;
    n=s.size();
    for(int i=0;i<n;i++)v.push_back(s[i]-'0');

    build();
    while(q--){
        cin>>x;
        v[x-1]=1-v[x-1];
        update();
        cout<<query()<<" ";
    }
}
