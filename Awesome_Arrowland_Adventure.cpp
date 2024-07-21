/*
MIT License

Copyright (c) 2024 tte0 (teomana,teoata17)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma GCC optimize("O3,fast-math,unroll-all-loops")
#include <bits/stdc++.h>
#define int i32
#define ff first
#define ss second
#define mset(x,y) memset(x,y,sizeof(x))
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);cout<<fixed<<setprecision(0);cerr<<fixed<<setprecision(0)
using namespace std;
typedef int_fast32_t i32;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
///////////////////////////////////////////////////////////////////
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int n,m,vis[500][500],d,x,y;

inline void solve(void){
    mset(vis,-1);
    cin>>n>>m;
    int v[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='N')v[i][j]=0;
            if(c=='E')v[i][j]=1;
            if(c=='S')v[i][j]=2;
            if(c=='W')v[i][j]=3;
            if(c=='X')v[i][j]=-1;
        }
    }

    priority_queue<iii,viii,greater<iii>> q;
    q.push({0,{0,0}});
    while(q.size()){
        d=q.top().ff,x=q.top().ss.ff,y=q.top().ss.ss;q.pop();
        //debug("q:",d,x,y);
        if(x==n-1 && y==m-1)return void(cout<<d);//answer
        if(vis[x][y]!=-1)continue;
        if(v[x][y]==-1)continue;
        vis[x][y]=d;

        for(int i=0;i<4;i++){
            int d=::d+(i-v[x][y]+4)%4;
            int x=::x+dx[i];
            int y=::y+dy[i];
            if(x<0 || y<0 || n<=x || m<=y || vis[x][y]!=-1)continue;
            q.push({d,{x,y}});
        }
    }
    return void(cout<<-1);
}   

signed main(void){
    fastio;
    solve();
}
