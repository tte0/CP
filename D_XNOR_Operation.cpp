// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
string s;

signed main(void){
    cin>>n>>s;
    int a[2]={1,0},cnt=0,ans=0;
    for(int i=0;i<n;i++){
        cnt+=(s[i]=='0');
        ans+=a[cnt%2];
        a[cnt%2]++;
    }
    cout<<ans<<endl;
}
