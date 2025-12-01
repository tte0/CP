// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=1e5+5;
constexpr int SQRT=320;
///////////////////////////////////////////////////////////
int n,ans[N],anspref[N];
vector<int> v,arr[N];

inline int upper_bound(int c,int val){
    int l=0,r=arr[c].size();
    while(l<r){
        int m=(l+r)/2;
        if(arr[c][m]<=val)l=m+1;
        else r=m;
    }
    return l;
}

inline int solve(int c,int x){
    int i=arr[c][0],ans=0;
    while(i<n){
        i=upper_bound(c,i+x);
        if(i==arr[c].size())i=n;
        else i=arr[c][i];
        ans++;
    }
    //cerr<<"sovle("<<c<<","<<x<<")="<<ans<<endl;
    return ans;
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> comp;
    for(auto i:v)comp.push_back(i);
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    for(auto& i:v)i=lower_bound(comp.begin(),comp.end(),i)-comp.begin();

    for(int i=0;i<n;i++){
        arr[v[i]].push_back(i);
    }

    
    for(int c=0;c<comp.size();c++){
        if(arr[c].size()>SQRT){
            for(int x=1;x<=n;x++){
                int t=solve(c,x);
                ans[x]+=t;
            }
        }
    }
}
