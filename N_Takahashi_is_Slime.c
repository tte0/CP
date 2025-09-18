// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <stdio.h>
#include <stdint.h>
const int N=5e5+5;
///////////////////////////////////////////////////////////
int n,v[N],L[N],R[N],st_min[2*N],st_max[2*N];
int64_t pref[N];

inline int min_query(int l,int r){
    int ans=INT32_MAX;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1)ans=min(ans,st_min[l++]);
        if(r&1)ans=min(ans,st_min[--r]);
    }
    return ans;
}
inline int max_query(int l,int r){
    int ans=INT32_MIN;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1)ans=max(ans,st_max[l++]);
        if(r&1)ans=max(ans,st_max[--r]);
    }
    return ans;
}
inline void min_update(int x,int val){
    for(st_min[x+=n]=val;x>1;x>>=1){
        st_min[x>>1]=min(st_min[x],st_min[x^1]);
    }
}
inline void max_update(int x,int val){
    for(st_max[x+=n]=val;x>1;x>>=1){
        st_max[x>>1]=max(st_max[x],st_max[x^1]);
    }
}

inline int64_t sum(int l,int r){
    return pref[r+1]-pref[l];
}

signed main(void){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        pref[i+1]=pref[i]+v[i];
        L[i]=R[i]=i;
    }

    vector<<int,int>> arr(n);
    for(int i=0;i<n;i++)arr[i]={v[i],i};
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        min_update(i,L[i]);
        max_update(i,R[i]);
    }
    for(const auto& [_,i]:arr){
        while(true){
            bool moved=0;
            while(0<L[i] && sum(L[i],R[i])>int64_t(v[L[i]-1])){
                L[i]=min_query(L[L[i]-1],R[i]);
                moved=1;
            }
            //cerr<<"moved L"<<endl;
            while(R[i]<n-1 && sum(L[i],R[i])>int64_t(v[R[i]+1])){
                R[i]=max_query(L[i],R[R[i]+1]);
                moved=1;
            }
            if(!moved)break;
        }
        min_update(i,L[i]);
        max_update(i,R[i]);
    }


    for(int i=0;i<n;i++)cout<<sum(L[i],R[i])<<" ";
}
