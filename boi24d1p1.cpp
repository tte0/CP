// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#pragma GCC optimize("O3")
#define int int_fast64_t
using namespace std;
constexpr int N=300005;
///////////////////////////////////////////////////////////
int n,k,x,p[N],c[N];
vector<tuple<int,int>> adj[N];
vector<vector<pair<int,int>>> v;

signed main(void){
    cin>>n>>k;
    const int K=k;
    for(int i=0;i<n;i++){
        cin>>c[i]>>p[i];p[i]--;
        if(p[i]!=-1)adj[p[i]].push_back({i,c[i]});
    }

    for(int i=0;i<n;i++){
        if(p[i]==-1)v.push_back({{0,c[i]}});
        else v.back().push_back({0,c[i]});
    }

    // for(auto _:v){
    //     cerr<<"v:";
    //     for(auto i:_)cerr<<"["<<i.first<<","<<i.second<<"],";
    //     cerr<<endl;
    // }
    // cerr<<endl;

    for(auto& v:v){
        vector<pair<int,int>> t;
        for(auto i:v){
            if(t.size() && t.back().second<0){
                t.back().second+=i.second;
            }
            else{
                t.push_back(i);
            }
            t.back().first=min(t.back().second,t.back().first);
        }
        v=t;
    }
    
    // for(auto _:v){
    //     cerr<<"v:";
    //     for(auto i:_)cerr<<"["<<i.first<<","<<i.second<<"],";
    //     cerr<<endl;
    // }
    // cerr<<endl;

    int ans=0;
    priority_queue<tuple<int,int,int,int>> q;
    for(int i=0;i<v.size();i++)q.push({v[i][0].first,v[i][0].second,i,0});
    while(q.size()){
        auto [x,y,i,j]=q.top();q.pop();
        if(y<0 || x+k<0)continue;
        k+=y;
        ans=max(ans,k-K);
        if(j+1<v[i].size())q.push({v[i][j+1].first,v[i][j+1].second,i,j+1});
    }

    cout<<ans<<endl;
}

