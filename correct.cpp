// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
#ifdef ONLINE_JUDGE
    #define cerr if(0)cerr
#endif
using namespace std;
constexpr int N=3e5+5;
///////////////////////////////////////////////////////////
int n,q;
vector<int> adj[N],val;
vector<pair<int,int>> edges;

int dfs(int node,int p=-1){
    int ans=val[node];
    for(auto i:adj[node]){
        if(i==p)continue;
        ans+=dfs(i,node);
    }
    return ans;
}

signed main(void){
    cin>>n;
    val.assign(n,1);
    for(int i=1;i<n;i++){
        static int x,y;
        cin>>x>>y;x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back({x,y});
    }

    cin>>q;
    while(q--){
        static int x,y;
        cin>>x;
        if(x==1){
            cin>>x>>y;x--;
            val[x]+=y;
        }
        else{
            cin>>x;x--;
            auto [a,b]=edges[x];
            for(size_t i=0;i<adj[a].size();i++){
                if(adj[a][i]==b){
                    adj[a].erase(adj[a].begin()+i);
                }
            }
            for(size_t i=0;i<adj[b].size();i++){
                if(adj[b][i]==a){
                    adj[b].erase(adj[b].begin()+i);
                }
            }
            cout<<abs(dfs(a)-dfs(b))<<endl;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
}
