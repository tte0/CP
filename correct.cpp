// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e7;
/////////////////////////////////////////////////////////// max 18 dig
int n,fp[19],ans[N];

inline int rev(int x){
    int ans=0;
    while(x){
        ans=ans*10+x%10;
        x/=10;
    }
    return ans;
}

signed main(void){
    for(int i=1;i<=N;i++){
        int x=rev(i)-i;
        if(0<=x && x<N)ans[x]++;
    }

    int x;
    cin>>x;
    cout<<ans[x]<<endl;

    for(int i=1;i<=N;i++){
        int y=rev(i)-i;
        if(y==x)cout<<i<<endl;
    }
}
