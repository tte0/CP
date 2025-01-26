// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

inline int f(int x){
    vector<int> temp={0};

    int ans=0,sum=0;
    map<int,int> mp;
    for(auto i:v){
        if(i==x){
            for(auto _:temp)mp[_]++;
            temp.clear();
        }
        sum+=i<=x?1:-1;
        ans+=mp[sum];
        temp.push_back(sum);
        //cerr<<ans<<",";
    }
    return ans;
}

inline void solve(void){
    cin>>n;
    v.resize(n);
    for(int& i:v)cin>>i;

    int ans=0;
    for(int i=1;i<=10;i++){
        ans+=f(i);
        //cerr<<endl;
    }

    cout<<n*(n+1)/2-ans<<endl;
    //cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();   
}
