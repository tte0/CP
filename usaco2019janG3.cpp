// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=10004;
///////////////////////////////////////////////////////////
int n,m,t,x,y,w,ans,vis[N],bt[N];
vector<int> v;
vector<tuple<int,int>> adj[N],nadj[N];

inline tuple<int,int,int> dfs(int node=0,int b=0){
    // cerr<<"dfs("<<node<<","<<b<<")\n";
    int ans=b*v[node],mx=0,sum=v[node];
    for(auto [i,w]:nadj[node]){
        auto [x,y,z]=dfs(i,b+w);
        ans+=x;
        mx=max(mx,y);
        sum+=z;
    }
    mx=max(mx,(b-t)*sum);
    // cerr<<">dfs: "<<ans<<","<<mx<<","<<sum<<endl;
    return {ans,mx,sum};
}

signed main(void){
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    memset(vis,-1,sizeof(vis));
    memset(bt,-1,sizeof(bt));
    cin>>n>>m>>t;
    v.resize(n);
    for(int& i:v)cin>>i;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;x--,y--;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    priority_queue<tuple<int,int,int>> q; //-cost,node,b
    q.push({0,0,-1});
    while(q.size()){
        auto [c,node,b]=q.top();q.pop();
        if(vis[node]==-c)bt[node]=min(bt[node],b);
        if(vis[node]!=-1)continue;
        vis[node]=-c;
        bt[node]=b;

        for(auto [i,w]:adj[node]){
            q.push({c-w,i,node});
        }
    }

    // cerr<<"bt:";for(int i=0;i<n;i++)cerr<<bt[i]<<",";cerr<<endl;

    for(int node=1;node<n;node++){
        int mn=1e18;
        for(auto [i,w]:adj[node]){
            if(i==bt[node]){
                mn=min(mn,w);
            }
        }
        nadj[bt[node]].push_back({node,mn});
    }

    auto [ans,mx,sum]=dfs();
    assert(sum==accumulate(v.begin(),v.end(),int(0)));

    cout<<mx<<endl;
}

