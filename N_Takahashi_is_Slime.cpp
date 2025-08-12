// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int64_t
using namespace std;
constexpr int N=5e5+5;
///////////////////////////////////////////////////////////
int n,v[N],L[N],R[N],b_r[N],b_l[N];
int pref[N];

inline int sum(int l,int r){
    return pref[r+1]-pref[l];
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cerr.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
        pref[i+1]=pref[i]+v[i];
        L[i]=R[i]=i;
    }

    stack<pair<int,int>> st;
    st.push({2e9,-1});
    for(int i=0;i<n;i++){
        while(st.top().first<=v[i])st.pop();
        b_l[i]=st.top().second;
        st.push({v[i],i});
    }
    while(st.size())st.pop();
    st.push({2e9,n});
    for(int i=n;i--;){
        while(st.top().first<=v[i])st.pop();
        b_r[i]=st.top().second;
        st.push({v[i],i});
    }

    int arr[n];
    for(int i=0;i<n;i++)arr[i]=i;
    sort(arr,arr+n,[&](const int& a,const int& b){
        return v[a]>v[b];
    });

    for(const auto& i:arr){
        if((i==0 || v[i-1]>=v[i]) && (i==n-1 || v[i]<=v[i+1]))continue;
        if(sum(b_l[i]+1,b_r[i]-1)>(b_l[i]==-1?1e18:v[b_l[i]])){
            L[i]=L[b_l[i]];
            R[i]=R[b_l[i]];
        }
        else if(sum(b_l[i]+1,b_r[i]-1)>(b_r[i]==n?1e18:v[b_r[i]])){
            L[i]=L[b_r[i]];
            R[i]=R[b_r[i]];
        }
        else{
            L[i]=b_l[i]+1;
            R[i]=b_r[i]-1;
        }
    }


    for(int i=0;i<n;i++)cout<<sum(L[i],R[i])<<" ";
}
