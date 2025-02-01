// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=505;
///////////////////////////////////////////////////////////
int n,ans;
vector<string> s;

signed main(void){
    cin>>n;
    s.resize(n);
    for(auto& i:s)cin>>i;

    priority_queue<tuple<int,int,int>> q;
    vector<vector<int>> vis(n,vector<int>(n,-1));
    q.push({0,0,0});
    while(q.size()){
        auto [c,x,y]=q.top();q.pop();
        if(vis[x][y]!=-1)continue;
        c-=(s[x][y]=='B');
        vis[x][y]=-c;

        if(0<x)q.push({c,x-1,y});
        if(0<y)q.push({c,x,y-1});
        if(x<n-1)q.push({c,x+1,y});
        if(y<n-1)q.push({c,x,y+1});
    }    
    ans+=vis[n-1][n-1];

    vis.assign(n,vector<int>(n,-1));
    q.push({0,0,n-1});
    while(q.size()){
        auto [c,x,y]=q.top();q.pop();
        if(vis[x][y]!=-1)continue;
        c-=(s[x][y]=='R');
        vis[x][y]=-c;

        if(0<x)q.push({c,x-1,y});
        if(0<y)q.push({c,x,y-1});
        if(x<n-1)q.push({c,x+1,y});
        if(y<n-1)q.push({c,x,y+1});
    }    
    ans+=vis[n-1][0];

    cout<<ans<<endl;
}
