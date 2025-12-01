// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=1e3+3;
///////////////////////////////////////////////////////////
int n,q,cnt,vis[N][N];
string s[N];
vector<tuple<int,int,char>> query;

bool inside(int x,int y){
    return (0<=x && x<n && 0<=y && y<n);
}

bool good(int x,int y){
    if(!inside(x,y))return false;

    return(
        ( (s[x][y]=='U' || s[x][y]=='?') && (!inside(x-1,y) || vis[x-1][y]) )  ||
        ( (s[x][y]=='D' || s[x][y]=='?') && (!inside(x+1,y) || vis[x+1][y]) )  ||
        ( (s[x][y]=='L' || s[x][y]=='?') && (!inside(x,y-1) || vis[x][y-1]) )  ||
        ( (s[x][y]=='R' || s[x][y]=='?') && (!inside(x,y+1) || vis[x][y+1]) )
    );
}

void dfs(int x,int y){
    if(!good(x,y) || vis[x][y])return;
    vis[x][y]++;
    cnt--;

    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

signed main(void){
    cin>>n>>q;
    for(int i=0;i<n;i++)s[i].assign(n,'?');
    query.resize(q);
    for(auto& [x,y,c]:query)cin>>x>>y>>c;

    for(auto& [x,y,c]:query){
        x--,y--;
        s[x][y]=c;
    }

    cnt=n*n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dfs(i,j);
        }
    }

    reverse(query.begin(),query.end());

    vector<int> ans;
    for(const auto& [x,y,c]:query){
        ans.push_back(cnt);
        s[x][y]='?';
        dfs(x,y);
    }

    reverse(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<endl;
}
