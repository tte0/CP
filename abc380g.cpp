// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=200005;
constexpr int MOD=998244353;
///////////////////////////////////////////////////////////
int n,k,st[2*N];
vector<int> v;

inline void update(int x,int val){
    for(st[x+=n]+=val;x>1;x>>=1)st[x>>1]=st[x]+st[x^1];
}

inline int query(int l,int r){
    int ans=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)ans+=st[l++];
        if(r&1)ans+=st[--r];
    }
    return ans;
}

inline int fp(int b,int p){
    int ans=1;
    while(p){
        if(p&1)ans=ans*b%MOD;
        b=b*b%MOD;
        p>>=1;
    }
    return ans;
}

inline int inv(int x){
    return fp(x,MOD-2);
}

signed main(void){
    cin>>n>>k;
    v.resize(n);
    for(int& i:v){
        cin>>i;
        i--;
    }

    int sum=0,cur=0,ans=0;

    for(int i=0;i<n;i++){
        sum=(sum+query(v[i]+1,n))%MOD;
        update(v[i],1);
    }

    memset(st,0,sizeof(st));
    int ex=k*(k+1)%MOD*inv(4)%MOD;
    for(int i=k;i<n;i++){
        ans=(ans+sum-cur+ex+MOD)%MOD;
        update()
    }
}

