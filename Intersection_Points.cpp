// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=(1<<18);
///////////////////////////////////////////////////////////
int n,ans,st[2*N];
vector<int> vx,vy,add[N],rem[N],qry[N];
vector<tuple<int,int,int,int>> v;

inline void compress(){
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    vx.resize(unique(vx.begin(),vx.end())-vx.begin());
    vy.resize(unique(vy.begin(),vy.end())-vy.begin());

    for(auto& [xa,ya,xb,yb]:v){
        xa=lower_bound(vx.begin(),vx.end(),xa)-vx.begin();
        xb=lower_bound(vx.begin(),vx.end(),xb)-vx.begin();
        ya=lower_bound(vy.begin(),vy.end(),ya)-vy.begin();
        yb=lower_bound(vy.begin(),vy.end(),yb)-vy.begin();
    }
}

inline void update(int x,int val){
    //cerr<<"update:"<<x<<","<<val<<endl;
    for(st[x+=2*n]+=val;x>1;x>>=1)st[x>>1]=st[x]+st[x^1];
}

inline void query(int l,int r){
    //cerr<<"query:"<<l<<","<<r<<endl;
    for(l+=2*n,r+=2*n;l<r;l>>=1,r>>=1){
        if(l&1)ans+=st[l++];
        if(r&1)ans+=st[--r];
    }
}

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& [xa,ya,xb,yb]:v){
        cin>>xa>>ya>>xb>>yb;
        vx.push_back(xa);
        vx.push_back(xb);
        vy.push_back(ya);
        vy.push_back(yb);
    }

    compress();
    //for(auto [a,b,c,d]:v)cerr<<"v:"<<a<<","<<b<<","<<c<<","<<d<<endl;

    for(auto& [xa,ya,xb,yb]:v){
        if(xa==xb){
            add[min(ya,yb)].push_back(xa);
            rem[max(ya,yb)].push_back(xa);
        }
        else{
            qry[ya].push_back(min(xa,xb)+(max(xa,xb)<<20));
        }
    }

    for(int t=0;t<2*n;t++){
        for(auto x:add[t])update(x,1);
        for(auto x:rem[t])update(x,-1);
        for(auto x:qry[t])query(x%(1<<20),(x>>20)+1);
    }

    cout<<ans<<endl;
}
