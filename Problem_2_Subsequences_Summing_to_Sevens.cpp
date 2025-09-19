// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,arr[7]={-1,INT32_MAX,INT32_MAX,INT32_MAX,INT32_MAX,INT32_MAX,INT32_MAX};

signed main(void){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin>>n;
    int sum=0,ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        ans=max(ans,i-arr[sum%7]);
        arr[sum%7]=min(arr[sum%7],i);
    }
    cout<<ans<<endl;
}
