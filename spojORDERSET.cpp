// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int n=1<<18;
///////////////////////////////////////////////////////////
int q,st[2*n];
vector<int> comp;
vector<tuple<char,int>> v;

inline void insert(int x){
    for(st[x+=n]=1;x>1;x>>=1){
        st[x>>1]=st[x]+st[x^1];
    }
}

inline void delet(int x){
    for(st[x+=n]=0;x>1;x>>=1){
        st[x>>1]=st[x]+st[x^1];
    }
}

inline string kth(int k){
    if(st[1]>k)return "invalid";
    int x=1;
    for(;x<n;){
        if(st[x]>=k)x=x<<1;
        else x=x<<1|1;
    }
    return to_string(x-n);
}

inline int count(int r){
    int ans=0,l=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)ans+=st[l++];
        if(r&1)ans+=st[--r];
    }
    return ans;
}

signed main(void){
    cin>>q;
    v.resize(q);
    for(auto& [c,x]:v){
        cin>>c>>x;
        comp.push_back(x);
    }

    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());

    for(auto& [c,x]:v){
        x=lower_bound(comp.begin(),comp.end(),x)-comp.begin()+1;
        cerr<<"v:"<<c<<","<<x<<endl;
        
        if(c=='I'){
            insert(x);
        }
        else if(c=='D'){
            delet(x);
        }
        else if(c=='K'){
            cout<<kth(x)<<endl;
        }
        else{
            cout<<count(x)<<endl;
        }
    }


}

