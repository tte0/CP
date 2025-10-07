// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e3+3;
///////////////////////////////////////////////////////////
int n,pref[N][N],u[N*N],l[N*N],d[N*N],r[N*N];
vector<vector<int>> v;
bitset<N> vis;

signed main(void){
    //freopen("art.in", "r", stdin);
    //freopen("art.out", "w", stdout);

    memset(u,-1,sizeof(u));
    memset(l,-1,sizeof(l));
    memset(d,-1,sizeof(d));
    memset(r,-1,sizeof(r));

    cin>>n;
    v.resize(n,vector<int>(n));
    for(auto& t:v)for(auto& i:t)cin>>i;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x=v[i][j];
            if(x){
                u[x]=(u[x]==-1?i:min(u[x],i));
                l[x]=(l[x]==-1?j:min(l[x],j));
                d[x]=(d[x]==-1?i:max(d[x],i));
                r[x]=(r[x]==-1?j:max(r[x],j));
            }
        }
    }

    for(int i=0;i<=n*n;i++){
        if(u[i]==-1)continue;
        pref[u[i]][l[i]]++;
        pref[u[i]][r[i]+1]--;
        pref[d[i]+1][l[i]]--;
        pref[d[i]+1][r[i]+1]++;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i)
                pref[i][j]+=pref[i-1][j];
            if(j)
                pref[i][j]+=pref[i][j-1];
            if(i && j)
                pref[i][j]-=pref[i-1][j-1];
        }
    }

    /*for(int i=0;i<=n;i++){
        cerr<<"pref: ";
        for(int j=0;j<=n;j++){
            cerr<<pref[i][j]<<",";
        }
        cerr<<endl;
    }cerr<<endl;*/

    int ans=n*n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(pref[i][j]>1){
                ans-=!(vis[v[i][j]]);
                vis[v[i][j]]=1;
            }
        }
    }

    cout<<ans<<endl;
}
