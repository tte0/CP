// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,q,cur,f[N],dp[N][3],ans[2*N];
vector<int> v,c,arr[2*N];

inline int median(int a,int b,int c){
    return a+b+c-min({a,b,c})-max({a,b,c});
}

inline void pull(int node){
    array<int,3> cost={c[node-1],c[node-1],c[node-1]};
    cost[f[node]]=0;
    if(2*node>n){
        dp[node][0]=cost[0];
        dp[node][1]=cost[1];
        dp[node][2]=cost[2];
        return;
    }

    dp[node][0]=dp[node][1]=dp[node][2]=1e18;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                dp[node][median(i,j,k)]=min(dp[node][median(i,j,k)],cost[i]+dp[node<<1][j]+dp[node<<1|1][k]);
            }
        }
    }
    return;
}

inline void update(int node,int val){
    f[node]=val;
    while(node){
        pull(node);
        node>>=1;
    }
}

signed main(void){
    cin>>n;
    v.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++)cin>>v[i]>>c[i];

    vector<int> comp={int(2e9)};
    for(const auto& i:v)comp.push_back(i),comp.push_back(i-1);
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    for(auto& i:v)i=lower_bound(comp.begin(),comp.end(),i)-comp.begin();
    for(int i=0;i<n;i++)arr[v[i]].push_back(i+1);

    /*cerr<<"comp: ";for(auto i:comp)cerr<<i<<" ";cerr<<endl;
    cerr<<"v: ";for(auto i:v)cerr<<i<<" ";cerr<<endl;
    for(int i=0;i<comp.size();i++){
        cerr<<"arr: ";
        for(const auto& j:arr[i])cerr<<j<<" ";
        cerr<<endl;
    }*/


    for(int i=n;i;i--){
        f[i]=2;
        pull(i);
    }
    ans[0]=dp[1][1];

    for(int i=1;i<comp.size();i++){
        for(const auto& ind:arr[i]){
            update(ind,1);
        }
        for(const auto& ind:arr[i-1]){
            update(ind,0);
        }
        ans[i]=dp[1][1];
    }


    cin>>q;
    while(q--){
        int x;
        cin>>x;
        x=lower_bound(comp.begin(),comp.end(),x)-comp.begin();
        cout<<ans[x]<<endl;
    }
}
