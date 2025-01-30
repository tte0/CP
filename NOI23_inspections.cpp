// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m,q,x,y,last[N],t,cnt[40000006];

signed main(void){
    memset(last,-1,sizeof(last));
    cin>>n>>m>>q;
    while(m--){
        cin>>x>>y;
        for(int i=x;i<=y;i++,t++){
            if(last[i]!=-1)cnt[t-last[i]]++;
            last[i]=t;
        }
    }

    int sum=0;
    for(int i=40000005;i--;)cnt[i]+=cnt[i+1];

    while(q--){
        cin>>x;
        if(x>(2+n)*(1+2000+1))cout<<0<<" ";
        else cout<<cnt[x+1]<<" ";
    }
}
