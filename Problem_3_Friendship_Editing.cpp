// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=16;
///////////////////////////////////////////////////////////
int n,m,adj[N][N];

signed main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        static int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x][y]=1;
    }

    for(int b=0;b<(1<<n);b++){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = (b & (1<<i)) || (b & (1<<j));
                cnt+=x^adj[i][j];
            }
        }
        //cerr<<"b,cnt: "<<b<<","<<cnt<<endl;
        ans=min(ans,cnt);
    }

    cout<<ans<<endl;
}
