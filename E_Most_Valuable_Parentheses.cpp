// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////

inline void solve(void){
    int n,x,y,ans=0;
    cin>>n>>x;
    ans=x;
    priority_queue<int> q;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        q.push(x);
        q.push(y);
        ans+=q.top();
        q.pop();
    }
    cin>>x;
    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
