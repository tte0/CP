// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e5+5;
constexpr int BLOCK=316;
///////////////////////////////////////////////////////////
int n,q,ans[N],dost[N][N/BLOCK+5];
vector<int> v,pref[BLOCK];
vector<tuple<int,int,int,int>> query;

signed main(void){
    cin>>n>>q;
    v.resize(n);
    query.resize(q);
    for(auto& i:v)cin>>i;
    for(int i=0,l,r,x;i<q;i++){
        cin>>l>>r>>x;
        l--;r--;
        query.push_back({l,r,x,i});
    }

    for(int i=1;i<BLOCK;i++){
        pref[i].resize(n+1);
        for(int j=0;j<n;j++)pref[i][j+1]=pref[i][j]+v[j]/i;
    }

    sort(query.begin(),query.end(),[](const auto& a,const auto& b){
        const auto& [ignore,ignore,xa,ignore]=a;
        const auto& [ignore,ignore,xb,ignore]=b;
        return xa<xb;
    });

    priority_queue<tuple<int,int>> q;
    for(int i=0;i<n;i++)q.push({});

    for(const auto& [l,r,x,i]:query){
        if(x<BLOCK){
            ans[i]=pref[x][r+1]-pref[x][l];
            continue;
        }
        
    }
}
