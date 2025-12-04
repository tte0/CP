// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=404;
///////////////////////////////////////////////////////////
int n,k,mn[N][N];
vector<int> v,comp;

inline int cost(int net,int fish){
    return net<fish?1e9:net-fish;
}

signed main(void){
    freopen("snakes.out","w",stdout);
    freopen("snakes.in","r",stdin);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mn[i][j]=1e9;
        }
    }

    cin>>n>>k;  
    v.resize(n);
    for(auto& i:v)cin>>i;

    comp=v;
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());

    vector<vector<int>> dp(k+1,vector<int>(comp.size(),1e9));

    for(int sz=0;sz<comp.size();sz++){
        dp[k][sz]=cost(comp[sz],v[0]);
        mn[0][k]=min(mn[0][k],dp[k][sz]);
    }

    for(int ind=1;ind<n;ind++){
        vector<vector<int>> dp_new(k+1,vector<int>(comp.size(),1e9));
        for(int left=0;left<=k;left++){
            for(int sz=0;sz<comp.size();sz++){
                if(left<k)dp_new[left][sz]=min(dp_new[left][sz],mn[ind-1][left+1]+cost(comp[sz],v[ind]));
                dp_new[left][sz]=min(dp_new[left][sz],dp[left][sz]+cost(comp[sz],v[ind]));
                mn[ind][left]=min(mn[ind][left],dp_new[left][sz]);
            }
        }
        swap(dp,dp_new);
    }

    /*for(int ind=1;ind<n;ind++){
        for(int left=0;left<=k;left++){
            cerr<<"dp: ";
            for(int sz=0;sz<comp.size();sz++){
                cerr<<dp_new[left][sz]<<" ";
            }
            cerr<<endl;
        }cerr<<endl;
    }*/

    int ans=1e9-1;
    for(int sz=0;sz<comp.size();sz++)ans=min(ans,dp[0][sz]);
    cout<<ans<<endl;
}
