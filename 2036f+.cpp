// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int l,r,i,k;

inline void solve(){
    cin>>l>>r>>i>>k;
    cout<<((((l>r)?0:((l!=0)?((l-1)%4==0?(l-1):((l-1)%4==1?1:((l-1)%4==2?(l-1)+1:0)))^(r%4==0?r:(r%4==1?1:(r%4==2?r+1:0))):(r%4==0)?r:((r%4==1)?1:((r%4==2)?r+1:0)))))^((((((l-1)/(1<<i)+((l-1)%(1<<i)>=k))>(r/(1<<i)+(r%(1<<i)>=k))-1)?(0):((((l-1)/(1<<i)+((l-1)%(1<<i)>=k))!=0)?(((((l-1)/(1<<i)+((l-1)%(1<<i)>=k))-1)%4==0?(((l-1)/(1<<i)+((l-1)%(1<<i)>=k))-1):((((l-1)/(1<<i)+((l-1)%(1<<i)>=k))-1)%4==1?1:((((l-1)/(1<<i)+((l-1)%(1<<i)>=k))-1)%4==2?(((l-1)/(1<<i)+((l-1)%(1<<i)>=k))-1)+1:0)))^(((r/(1<<i)+(r%(1<<i)>=k))-1)%4==0?((r/(1<<i)+(r%(1<<i)>=k))-1):(((r/(1<<i)+(r%(1<<i)>=k))-1)%4==1?1:(((r/(1<<i)+(r%(1<<i)>=k))-1)%4==2?((r/(1<<i)+(r%(1<<i)>=k))-1)+1:0)))):(((r/(1<<i)+(r%(1<<i)>=k))-1)%4==0?((r/(1<<i)+(r%(1<<i)>=k))-1):(((r/(1<<i)+(r%(1<<i)>=k))-1)%4==1?1:(((r/(1<<i)+(r%(1<<i)>=k))-1)%4==2?((r/(1<<i)+(r%(1<<i)>=k))-1)+1:0)))))<<i)^((((r/(1<<i)+(r%(1<<i)>=k))-((l-1)/(1<<i)+((l-1)%(1<<i)>=k)))&1)*k)))<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}

