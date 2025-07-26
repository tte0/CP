// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,s,x;
vector<int> v;

inline int f(vector<int> v){
    //cerr<<"sub:";for(auto i:v)cerr<<i<<",";cerr<<endl;

    int n=v.size();
    map<int,int> mp;
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        mp[sum]++;
    }

    int cur=0,last=-1,ans=0;
    for(int i=0;i<n;i++){
        cur+=v[i];
        if(v[i]==x){
            for(int _=i,temp=0;last<_;_--){
                temp+=v[_];
                ans+=mp[s+cur-temp];
            }
            last=i;
        }
        mp[cur]--;
    }

    return ans;
}

inline void solve(void){
    cin>>n>>s>>x;
    v.resize(n);
    for(auto& i:v)cin>>i;

    int ans=0,last=0;
    for(int i=0;i<n;i++){
        if(v[i]>x){
            ans+=f(vector<int>(v.begin()+last,v.begin()+i));
            last=i+1;
        }
    }
    ans+=f(vector<int>(v.begin()+last,v.end()));

    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
