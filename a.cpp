// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=5e5+5;
///////////////////////////////////////////////////////////
int n,L[N],R[N],pref[N];
vector<int> v;

struct segtree{
    int n;
    vector<int> st_min,st_max;
    segtree(int __n){
        n=__n;
        st_min.resize(2*n);
        st_max.resize(2*n);
        for(int i=0;i<n;i++){
            min_update(i,L[i]);
            max_update(i,R[i]);
        }
    }
    inline int min_query(int l,int r){
        //cerr<<"min_query:"<<l<<","<<r<<endl;
        int ans=INT64_MAX;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1)ans=min(ans,st_min[l++]);
            if(r&1)ans=min(ans,st_min[--r]);
        }
        return ans;
        //cerr<<"min_query ok"<<endl;
    }
    inline int max_query(int l,int r){
        //cerr<<"max_query:"<<l<<","<<r<<endl;
        int ans=INT64_MIN;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1)ans=max(ans,st_max[l++]);
            if(r&1)ans=max(ans,st_max[--r]);
        }
        return ans;
        //cerr<<"max_query ok"<<endl;
    }
    inline void min_update(int x,int val){
        //cerr<<"min_update:"<<x<<","<<val<<endl;
        for(st_min[x+=n]=val;x>1;x>>=1){
            st_min[x>>1]=min(st_min[x],st_min[x^1]);
        }
        //cerr<<"min_update ok"<<endl;
    }
    inline void max_update(int x,int val){
        //cerr<<"max_update:"<<x<<","<<val<<endl;
        for(st_max[x+=n]=val;x>1;x>>=1){
            st_max[x>>1]=max(st_max[x],st_max[x^1]);
        }
        //cerr<<"max_update ok"<<endl;
    }
};

inline int sum(int l,int r){
    return pref[r+1]-pref[l];
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cerr.tie(NULL);

    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    for(int i=0;i<n;i++)pref[i+1]=pref[i]+v[i];
    for(int i=0;i<n;i++)L[i]=R[i]=i;

    vector<tuple<int,int>> arr(n);
    for(int i=0;i<n;i++)arr[i]={v[i],i};
    sort(arr.begin(),arr.end());

    segtree st(n);
    for(auto [ignore,i]:arr){
        //cerr<<"i:"<<i<<endl;
        while(true){
            //cerr<<"L,R:"<<L[i]<<","<<R[i]<<endl;
            bool moved=0;
            while(0<L[i] && sum(L[i],R[i])>v[L[i]-1]){
                //cerr<<"moving L"<<endl;
                L[i]=st.min_query(L[L[i]-1],R[i]);
                moved=1;
                //cerr<<"L,R:"<<L[i]<<","<<R[i]<<endl;
            }
            //cerr<<"moved L"<<endl;
            while(R[i]<n-1 && sum(L[i],R[i])>v[R[i]+1]){
                //cerr<<"moving R"<<endl;
                R[i]=st.max_query(L[i],R[R[i]+1]);
                moved=1;
                //cerr<<"L,R:"<<L[i]<<","<<R[i]<<endl;

                //cerr<<"R:";for(int i=0;i<n;i++)//cerr<<R[i]<<",";//cerr<<endl;
            }
            if(!moved)break;
        }
        st.min_update(i,L[i]);
        st.max_update(i,R[i]);
    }


    for(int i=0;i<n;i++)cout<<sum(L[i],R[i])<<" ";
}
