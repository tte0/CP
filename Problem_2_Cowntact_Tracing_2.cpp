/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
int n;
string s;

signed main(void){
    cin>>n>>s;

    vector<pair<char,int>> v;
    for(int i=0;i<n;i++){
        if(i==0 || s[i-1]!=s[i])v.push_back({s[i],1});
        else v.back().second++;
    }
                for(auto i:v)cerr<<i.first<<","<<i.second<<endl;

    int d=1e9;
    if(v[0].first=='1')d=v[0].second-1;
    if(v.size()>1 && v.back().first=='1')d=min(d,v.back().second-1);
    for(int i=1;i<v.size()-1;i++){
        if(v[i].first=='1')d=min(d,(v[i].second-1)/2);
    }

    int ans=0;
    if(v[0].first=='1')ans+=(v[0].second-1)/(2*d+1)+1;
    if(v.size()>1 && v.back().first=='1')ans+=(v.back().second-1)/(2*d+1)+1;
    for(int i=1;i<v.size()-1;i++){
        if(v[i].first=='1')ans+=(v[i].second-1)/(2*d+1)+1;
    }

    cout<<ans<<endl;
}
/*
d=0,111111 -> 6
d=1,111111 -> 2
d=2,111111 -> 2
d=3,111111 -> 1
d=4,111111 -> 1
d=5,111111 -> 1

d=0,1111111 -> 7
d=1,1111111 -> 3
d=2,1111111 -> 2
d=3,1111111 -> 1
d=4,1111111 -> 1
d=5,1111111 -> 1
d=6,1111111 -> 1
*/