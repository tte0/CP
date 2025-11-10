// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e5+5;
constexpr int INF=INT64_MAX/4;
///////////////////////////////////////////////////////////
int n,cnt[N],vis[N];
vector<int> c,t,adj[N],dadj[N];
vector<tuple<int,int>> ans;

inline void process(queue<int>& q){
    while(q.size()){
        int node=q.front();q.pop();
        cnt[node]--;
        ans.push_back({node,t[node]});
        for(int i:dadj[node]){
            if(!--cnt[i])q.push(i);
        }
    }
}

int dfs(int node){
    if(cnt[node]==-1 || vis[node]++)return 0;
    int t=1;
    for(auto i:dadj[node])t+=dfs(i);
    return t;
}

signed main(void){
    int n;
    cin>>n;
    c.resize(n);
    t.resize(n);
    for(auto& i:c)cin>>i;
    for(auto& i:t)cin>>i;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if(n==2 && c[0]!=t[0]){
        cout<<-1<<endl;
        return 0;
    }
    cout<<"0 1\n";return 0;
    

    for(int node=0;node<n;node++){
        for(int i:adj[node]){
            if(t[i]==c[node]){
                dadj[node].push_back(i);
                cnt[i]++;
            }
        }
    }

    /*for(int i=0;i<n;i++){
        cerr<<"dadj["<<i<<"]: {";
        for(int j:dadj[i])cerr<<j<<",";
        cerr<<"}\n";
    }cerr<<endl;*/

    queue<int> q;
    for(int i=0;i<n;i++){
        if(cnt[i]==0)q.push(i);
    }

    process(q);

    //for(auto [a,b]:ans)cerr<<a<<","<<b<<endl;

    int c=0;
    for(int i=0;i<n;i++){
        int t=dfs(i);
        if(t)c+=t+1;
    }

    cout<<ans.size()+c<<" 0\n";
}
