// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int A=2e5+5;
///////////////////////////////////////////////////////////
int n,k;
vector<int> v,divisor[A];

inline void divs(){
    for(int i=1;i<A;i++){
        for(int j=i;j<A;j+=i){
            divisor[j].push_back(i);
        }
    }
}

inline void solve(){
    cin>>n>>k;
    v.resize(n);
    for(auto& i:v)cin>>i;

    vector<int> next(n+1,n);
    for(int i=n;i--;){
        next[i]=next[i+1];
        if(v[i]>=k && *lower_bound(divisor[v[i]].begin(),divisor[v[i]].end(),k)==k)next[i]=i;
    }

    //cerr<<"nest: ";for(int i=0;i<n;i++)cerr<<next[i]<<" ";cerr<<endl;

    vector<int> mp(n+2,0);

    int l=0,r=0,cnt=0,ans=0;
    auto push_l=[&](){
        for(auto d:divisor[v[l]]){
            if(d>k)break;
            cnt-=!--mp[d];
        }
        l++;
        //cerr<<"push l to "<<l<<" mp[k]="<<mp[k]<<endl;
    };
    auto push_r=[&](){
        for(auto d:divisor[v[r]]){
            if(d>k)break;
            cnt+=!mp[d]++;
        }
        r++;
        //cerr<<"push r to "<<r<<" mp[k]="<<mp[k]<<endl;
    };
    while(l<n && r<=n){
        //cerr<<"l,r:"<<l<<" "<<r<<" (main loop)"<<endl;
        while((cnt<k-1 || mp[k]) && l<n && r<n){
            while(cnt<k-1 && r<n){
                push_r();
            }
            while(mp[k] && l<n){
                push_l();
            }
        }
        if(!(l<n && r<=n))break;
        //cerr<<"l,r:"<<l<<" "<<r<<" (end of loop)"<<mp[k]<<cnt<<endl;
        if(!(cnt<k-1 || mp[k]))ans+=next[r-1]-r+1;
        push_l();
    }

    cout<<ans<<endl;

    //cerr<<"---------------------"<<endl;
}

signed main(void){
    divs();
    int t;
    cin>>t;
    while(t--)solve();    
}
