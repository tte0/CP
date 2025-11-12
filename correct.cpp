// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast16_t
using namespace std;
constexpr int N=1e4;
///////////////////////////////////////////////////////////
int n,m,k;
int arr[N][N];
vector<tuple<int,int>> v;

signed main(void){
    cin>>n>>m>>k;
    v.resize(k);
    for(auto& [a,b]:v)cin>>a>>b;

    for(int i=0;i<k-1;i++){
        auto [xa,ya]=v[i];
        xa--,ya--;
        for(int j=i+1;j<k;j++){
            auto [xb,yb]=v[j];
            xb--,yb--;
            arr[i][j]=arr[j][i]=1LL<<(max(abs(xa-xb),abs(ya-yb)));
        }
    }

    vector<bool> vis(k,false);
    vector<int> bt(k);bt[0]=-1;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    q.push({0,0,-1});
    while(q.size()){
        auto [c,node,_bt]=q.top();q.pop();
        if(vis[node])continue;
        vis[node]=1;
        bt[node]=_bt;
        if(node==k-1){
            vector<int> t;
            while(node!=-1){
                t.push_back(node);
                node=bt[node];
            }
            reverse(t.begin(),t.end());

            cout<<t.size()<<endl;
            for(auto i:t)cout<<1+i<<" ";
            return 0;
        }
        for(int i=0;i<k;i++){
            if(i==node)continue;
            q.push({c+arr[node][i],i,node});
        }
    }
    abort();
}
