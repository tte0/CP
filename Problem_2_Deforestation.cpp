// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
struct segtree{
    int n;
    vector<int> st;
    segtree(int _n){
        n=_n;
        st.resize(2*n);
    }
    void insert(int x){
        for(st[x+=n]++;x>1;x>>=1){
            st[x>>1]=st[x]+st[x^1];
        }
    }
    int query(int l,int r){
        int ans=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};
///////////////////////////////////////////////////////////
int n,k;
vector<int> v;
vector<tuple<int,int,int>> arr;

inline void compress(int& x,const vector<int>& comp){
    x=lower_bound(comp.begin(),comp.end(),x)-comp.begin();
}

inline void debug(stack<int> st){
    cerr<<"st: ";
    while(st.size()){
        cerr<<st.top()<<",";
        st.pop();
    }
    cerr<<endl;
}

inline void solve(){
    cin>>n>>k;
    v.resize(n);
    arr.resize(k);
    for(auto& i:v)cin>>i;
    for(auto& [l,r,t]:arr)cin>>l>>r>>t;

    vector<int> comp;
    for(auto i:v)comp.push_back(i);
    for(auto [l,r,t]:arr)comp.push_back(l),comp.push_back(r);
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    for(auto& i:v)compress(i,comp);
    for(auto& [l,r,t]:arr)compress(l,comp),compress(r,comp);


    sort(v.begin(),v.end());
    sort(arr.begin(),arr.end(),[](const auto& a,const auto& b){
        const auto [la,ra,ta]=a;
        const auto [lb,rb,tb]=b;
        return ra<rb;
    });

    /*cerr<<"v: ";for(auto i:v)cerr<<i<<" ";cerr<<endl;
    for(const auto& [l,r,t]:arr){
        cerr<<"arr: ["<<l<<","<<r<<","<<t<<"]"<<endl;
    }cerr<<endl;*/

    int p=0;
    stack<int> stck;
    segtree sgtr(comp.size());
    for(auto [l,r,t]:arr){
        while(p<n && v[p]<=r)stck.push(v[p++]);
        //debug(stck);
        int cnt=t-sgtr.query(l,r+1);
        while(cnt>0){
            //assert(stck.size());
            sgtr.insert(stck.top());
            stck.pop();
            cnt--;
        }
    }

    cout<<n-sgtr.query(0,comp.size())<<endl;

    //cerr<<"-------------------------------"<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }    
}
