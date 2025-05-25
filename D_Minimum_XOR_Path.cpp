// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m,adj[10][10];

signed main(void){
    memset(adj,-1,sizeof(adj));
    cin>>n>>m;    
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        adj[x][y]=w;
        adj[y][x]=w;
    }
    
    int ans=(adj[0][n-1]!=-1?adj[0][n-1]:INT64_MAX);

    if(n==2){
        cout<<ans<<endl;
        return 0;
    }

    vector<int> perm;
    for(int i=1;i<n-1;i++)perm.push_back(i);

    do{
        int cnt=0,prev=0;
        for(auto i:perm){
            if(adj[prev][i]==-1)break;
            cnt^=adj[prev][i];
            if(adj[i][n-1]!=-1)ans=min(ans,cnt^adj[i][n-1]);
            prev=i;
        }
    }while(next_permutation(perm.begin(),perm.end()));

    cout<<ans<<endl;
}
