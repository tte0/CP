// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> v;

inline void solve(){
    cin>>n>>k;
    v.resize(n);
    for(auto& i:v)cin>>i;

    sort(v.begin(),v.end());

    priority_queue<int> q;
    stack<tuple<int,int>> spare;
    spare.push({v.back()+1,v.back()+n});
    for(int i=n-1;i--;){
        if(v[i]==v[i+1]){
            auto [l,r]=spare.top();spare.pop();
            q.push(-(l-v[i]));
            l++;
            if(l!=r)spare.push({l,r});
        }
        else if(v[i]+1==v[i+1]){
            
        }
        else{
            spare.push({v[i]+1,v[i+1]});
        }
    }

    while(q.size()){
        if(-q.top()>k)break;
        k+=q.top();
        q.pop();
    }

    cout<<n-q.size()<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
