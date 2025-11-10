// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e3+3;
///////////////////////////////////////////////////////////
int n,m;
vector<int> adj[N];

signed main(void){
    cin>>n>>m;
    if(n&1 || (n/2)*(n/2-1)>m){
        cout<<"impossible\n";
        return 0;
    }    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n,false);
    set<int> 
}
