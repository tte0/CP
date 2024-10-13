/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
int n,cnt[26],sum[26];
string s;

signed main(void){
    cin>>s;
    n=s.size();
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=i*cnt[s[i]-'A']-sum[s[i]-'A'];
        cnt[s[i]-'A']++;
        sum[s[i]-'A']+=i+1;
    }
    cout<<ans<<endl;
}
