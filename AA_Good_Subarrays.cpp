// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////

inline void solve(void){
    int n;
    string s;
    vector<int> v;
    cin>>n>>s;
    for(int i=0;i<n;i++)v.push_back(s[i]-'0'+(i?v[i-1]:0));
    map<int,int> mp={{1,1}};
    for(int i=0;i<n;i++)mp[v[i]-i]++;
    int ans=0;
    for(auto [key,count]:mp){
        //cerr<<key<<"->"<<count<<endl;
        ans+=count*(count-1)/2;
    }
    cout<<ans<<endl;
    //cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
