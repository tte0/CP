// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e6+6;
///////////////////////////////////////////////////////////
int n,m,p[N],ptr[N],cnt[N],ans=-1,vis[N];
vector<int> v[N];
vector<vector<int>> r,u;

signed main(void){
    fill(ptr,ptr+N,0);
    cin>>n>>m;
    r.resize(n,vector<int>(m));    
    u.resize(n,vector<int>(m));    
    for(auto& _:r)for(auto& i:_)cin>>i;
    for(auto& _:u)for(auto& i:_)cin>>i;
    u.push_back(vector<int>(m,0));

    for(int j=0;j<m;j++){
        v[j].resize(n);
        iota(v[j].begin(),v[j].end(),0);
        sort(v[j].begin(),v[j].end(),[&](int a,int b){
            return r[a][j]<r[b][j];
        });
    }

    /*for(int j=0;j<m;j++){
        cerr<<"v:";
        for(auto i:v[j])cerr<<i<<",";
        cerr<<endl;
    }*/

    queue<int> q;
    q.push(n);
    while(q.size()){
        int ind=q.front();q.pop();
        //cerr<<"q:"<<ind<<endl;
        ans++;
        for(int j=0;j<m;j++)p[j]+=u[ind][j];
        for(int j=0;j<m;j++){
            while(ptr[j]<n && r[v[j][ptr[j]]][j]<=p[j]){
                cnt[v[j][ptr[j]]]++;
                if(cnt[v[j][ptr[j]]]==m)q.push(v[j][ptr[j]]);
                ptr[j]++;
            }
        }

        //cerr<<"ptr:";for(int i=0;i<m;i++)cerr<<ptr[i]<<",";cerr<<endl;
        //cerr<<"cnt:";for(int i=0;i<n;i++)cerr<<cnt[i]<<",";cerr<<endl;
    }

    cout<<ans<<endl;
}
