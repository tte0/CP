// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;
string s;

inline int f(string& s){
    cerr<<s<<endl;
    int n=s.size();
    vector<int> z(n,0);

    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<r)z[i]=min(r-i,z[i-l]);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])z[i]++;
        if(i>=r)l=i,r=i+z[i];
    }

    //cerr<<"z: ";for(auto i:z)cerr<<i<<",";cerr<<endl;

    for(int i=1;i<n;i++){
        if(z[i]==n-i && n%i==0){
            return i;
        }
    }
    return n;
}

inline void solve(){
    cin>>n>>s;
    v.resize(n);
    for(auto& i:v)cin>>i;
    for(auto& i:v)i--;

    int ans=1;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        int p=i;
        string t;
        while(!vis[p]++){
            t.push_back(s[p]);
            p=v[p];
        }

        int val=f(t);
        ans=lcm(ans,val);

        //cerr<<val<<endl;
    }
    //cerr<<endl;
    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    } 
}
