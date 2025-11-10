// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=203;
struct point{
    int x,y;
};
struct line{
    point l,r;
};
struct cost{
    deque<line> pos,neg;
    cost& operator+=(const cost& other){
        cost ans;
    }
};  
cost min(const cost& a,const cost& b){

}
///////////////////////////////////////////////////////////
int n,m,q,ans[N][N][N];
vector<tuple<int,int,int>> adj[N];



signed main(void){
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int x,y,w,r;
        cin>>x>>y>>w>>r;
        x--,y--;
        adj[x].push_back({y,w,r});
    }

    for(int d=1)

    while(q--){

    }
}
