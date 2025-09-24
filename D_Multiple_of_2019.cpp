// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,cnt[2019]={1};
string s;

signed main(void){
    cin>>s;
    n=s.size();
    reverse(s.begin(),s.end());
    int ans=0,sum=0,ten=1;
    for(int i=0;i<n;i++){
        sum=(sum+ten*(s[i]-'0'))%2019;
        ans+=cnt[sum]++;
        ten=(ten*10)%2019;
    }

    cout<<ans<<endl;
}
