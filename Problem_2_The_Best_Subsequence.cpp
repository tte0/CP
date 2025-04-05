// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=8e5+5;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,m,q;
vector<int> points,arr,pref;
vector<tuple<int,int>> updates;
vector<tuple<int,int,int>> querys;

constexpr inline int fp(int p){
    int result=1,b=2;
    while(p){
        if(p&1)result=(result*b)%MOD;
        p>>=1;
        b=(b*b)%MOD;
    }
    return result;
}

inline int place(int x){
    int px=lower_bound(points.begin(),points.end(),x)-points.begin();
    assert(points[px]==x);
    return px;
}

inline void debug(){
    cerr<<"points: ";for(auto i:points)cerr<<i<<",";cerr<<endl;
    cerr<<"arr: ";for(auto i:arr)cerr<<i<<",";cerr<<endl;
    cerr<<"pref: ";for(auto i:pref)cerr<<i<<",";cerr<<endl;
}

signed main(void){
    // input
    cin>>n>>m>>q;
    updates.resize(m);
    querys.resize(q);
    for(auto& [l,r]:updates){
        cin>>l>>r;
        r++;
        points.push_back(l);
        points.push_back(r);
    }
    for(auto& [l,r,k]:querys){
        cin>>l>>r>>k;
        points.push_back(l);
        points.push_back(r);
    }

    // compress
    sort(points.begin(),points.end());
    points.resize(unique(points.begin(),points.end())-points.begin());

    //
    arr.resize(points.size());
    for(auto [l,r]:updates){
        int pl=place(l);
        int pr=place(r);
        arr[pl]^=1;
        arr[pr]^=1;
    }
    for(int i=1;i<arr.size();i++)arr[i]^=arr[i-1];

    // 1-prefix [0,x)
    pref.resize(arr.size());
    for(int i=0;i<points.size()-1;i++){
        pref[i+1]=(pref[i]+arr[i]*(points[i+1]-points[i]))%MOD;
    }

    debug();
    
    // value-suffix
}
