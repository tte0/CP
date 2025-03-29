// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h> 
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k,x,arr[5005];
unordered_map<int,pair<int,int>> mp;
 
signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;  
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 
    mp.reserve(1<<20);
    mp.max_load_factor(0.25);
 
    for(int i=0;i<n-1;i++){
        if(k-3<arr[i])continue;
        for(int j=i+1;j<n;j++){
            if(k-2<arr[i]+arr[j])continue;
            mp[arr[i]+arr[j]]={i,j};
        }
    }
 
    for(int i=0;i<n-1;i++){
        if(k-3<arr[i])continue;
        for(int j=i+1;j<n;j++){
            if(k-2<arr[i]+arr[j])continue;
            auto it=mp.find(k-arr[i]-arr[j]);
            if(it!=mp.end() && (*it).second.first!=i && (*it).second.second!=i && (*it).second.first!=j && (*it).second.second!=j){
                cout<<i+1<<" "<<j+1<<" "<<(*it).second.first+1<<" "<<(*it).second.second+1<<endl;
                return 0;
            }
        }
    }
 
    cout<<"IMPOSSIBLE"<<endl;
}