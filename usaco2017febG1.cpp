// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=102;
///////////////////////////////////////////////////////////
int n,t,vis[N][N][3];
vector<vector<int>> v;

signed main(void){
    freopen("visitfj.in","r",stdin);
    freopen("visitfj.out","w",stdout);
    memset(vis,-1,sizeof(vis));
    cin>>n>>t;
    v.resize(n,vector<int>(n));
    for(auto& _:v)for(auto& i:_)cin>>i;

    priority_queue<tuple<int,int,int,int>> q; //-cost,x,y,steps
    q.push({0,0,0,0});
    while(q.size()){
        auto [c,x,y,s]=q.top();q.pop();
        if(x<0 || x>=n || y<0 || y>=n)continue;
        if(s==3)c-=v[x][y],s=0;
        if(vis[x][y][s]!=-1)continue;
        vis[x][y][s]=c;

        q.push({c-t,x+1,y,s+1});
        q.push({c-t,x,y+1,s+1});
        q.push({c-t,x-1,y,s+1});
        q.push({c-t,x,y-1,s+1});
    }

    cout<<-max({vis[n-1][n-1][0],vis[n-1][n-1][1],vis[n-1][n-1][2]})<<endl;
}

