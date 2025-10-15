// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> v;

inline void solve(){
    cin>>n>>k;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> saving(n);
    for(int i=0;i<n;i++){
        saving[i]=v[i]-(n-i-1);
    }
    
    //cerr<<"v: ";for(auto i:v)cerr<<i<<",";cerr<<endl;

    vector<int> t(n),vis(n,0);
    iota(t.begin(),t.end(),0);
    sort(t.begin(),t.end(),[&](const int& a,const int& b){
        return saving[a]>saving[b];
    });
    
    //cerr<<"t: ";for(auto i:t)cerr<<i<<",";cerr<<endl;

    for(int i=0;i<k;i++)vis[t[i]]++;

    //cerr<<"vis: ";for(auto i:vis)cerr<<i<<",";cerr<<endl;

    int ans=0,cnt=0;
    for(int i=0;i<n;i++){
        if(vis[i])cnt++;
        else ans+=v[i]+cnt;
    }

    cout<<ans<<endl;
    //cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
