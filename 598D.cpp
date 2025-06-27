// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e6+5;
///////////////////////////////////////////////////////////
int n,m,q,vis[N];
vector<int> adj[N],bt;
string s[1003];

inline int f(int x,int y){return m*x+y;}

inline int dfs(int node){
    if(vis[node]++)return 0;
    //cerr<<"dfs:"<<node<<endl;
    int ans=4-adj[node].size();
    bt.push_back(node);
    for(auto i:adj[node])ans+=dfs(i);
    return ans;
}

signed main(void){
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)cin>>s[i];

    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(s[i][j]=='*')continue;
            if(s[i][j-1]=='.'){
                adj[f(i,j)].push_back(f(i,j-1));
            }
            if(s[i][j+1]=='.'){
                adj[f(i,j)].push_back(f(i,j+1));
            }
            if(s[i-1][j]=='.'){
                adj[f(i,j)].push_back(f(i-1,j));
            }
            if(s[i+1][j]=='.'){
                adj[f(i,j)].push_back(f(i+1,j));
            }
        }
    }

    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(vis[f(i,j)] || s[i][j]=='*')continue;
            int x=dfs(f(i,j));
            for(auto _:bt)vis[_]=x;
            bt.clear();
        }
    }

    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)cerr<<vis[f(i,j)]<<",";
        cerr<<endl;
    }*/

    while(q--){
        static int x,y;
        cin>>x>>y;x--,y--;
        cout<<vis[f(x,y)]<<endl;
    }
}
