// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m,k;
vector<vector<int>> v,vis;
signed main(void){
    cin>>n>>m>>k;
    v.resize(n,vector<int>(m));
    vis.resize(n,vector<int>(m,-1));
    for(auto& _:v)for(auto& i:_)cin>>i;

    priority_queue<tuple<int,int,int>> q;//time,x,y
    for(int i=0;i<n;i++){
        q.push({-v[i][0],i,0});
        q.push({-v[i][m-1],i,m-1});
    }
    for(int j=0;j<m;j++){
        q.push({-v[0][j],0,j});
        q.push({-v[n-1][j],n-1,j});
    }

    while(q.size()){
        auto [t,x,y]=q.top();q.pop();
        if(vis[x][y]!=-1)continue;

        vis[x][y]=-t;
        if(x!=0)  q.push({min(t,-v[x-1][y]),x-1,y});
        if(y!=0)  q.push({min(t,-v[x][y-1]),x,y-1});
        if(x!=n-1)q.push({min(t,-v[x+1][y]),x+1,y});
        if(y!=m-1)q.push({min(t,-v[x][y+1]),x,y+1});
    }

    vector<int> ans(100005);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[vis[i][j]]++;
        }
    }
    for(int i=1;i<100005;i++)ans[i]+=ans[i-1];
    for(int i=1;i<=k;i++)cout<<n*m-ans[i]<<endl;
}
