// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<tuple<int,int>> v;

inline void solve(){
    cin>>n;
    v.resize(n);
    for(auto& [s,t]:v)cin>>s>>t;

    sort(v.begin(),v.end(),[](const auto& a,const auto& b){
        auto [sa,ta]=a;
        auto [sb,tb]=b;
        return sa+ta<sb+tb;
    });

    priority_queue<int> q;
    int sum=0;
    for(auto [s,t]:v){
        sum+=t;
        q.push(t);
        while(sum>s+t){
            sum-=q.top();
            q.pop();
        }
    }
    cout<<q.size()<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
