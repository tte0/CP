// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e5+5;
///////////////////////////////////////////////////////////
int n,m,ans[N];
vector<int> v;

signed main(void){
    cin>>n>>m;
    v.resize(n);
    for(auto& i:v)cin>>i;    

    priority_queue<tuple<int,int>> q;
    for(int i=0;i<n;i++)q.push({v[i],i});

    while(q.size()){
        auto [val,i]=q.top();q.pop();
        if(ans[i])continue;
        assert(val>=v[i]);
        ans[i]=val;
        if(i<n-1)q.push({val-m,i+1});
        if(i>0)q.push({val-m,i-1});
    }

    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}
