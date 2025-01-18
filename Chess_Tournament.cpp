// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,x;
vector<tuple<int,int>> ans;
priority_queue<tuple<int,int>> q;

signed main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        q.push({x,i+1});
    }

    while(q.size()){
        auto [cnt,x]=q.top();q.pop();
        if(q.size()<cnt){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }

        vector<tuple<int,int>> t;
        for(int i=0;i<cnt;i++){
            auto [a,b]=q.top();q.pop();
            ans.push_back({x,b});
            t.push_back({a-1,b});
        }

        for(auto i:t)q.push(i);
    }

    cout<<ans.size()<<endl;
    for(auto [a,b]:ans)cout<<a<<" "<<b<<endl;
} 
