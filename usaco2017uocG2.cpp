// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
///////////////////////////////////////////////////////////
int n,x,cnt,mp[N];
vector<int> v;
vector<tuple<int,int>> ranges;

signed main(void){
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    memset(mp,-1,sizeof(mp));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(!x)continue;
        if(mp[x]==-1)mp[x]=cnt++;
        v.push_back(mp[x]);
    }

    // cerr<<"v:";for(int i:v)cerr<<i<<",";cerr<<endl;

    ranges.resize(cnt,{1e9,-1});
    for(int i=0;i<v.size();i++){
        auto& [a,b]=ranges[v[i]];
        a=min(a,i);
        b=max(b,i);
    }

    int ans=0;
    stack<int> st;
    for(int i=0;i<v.size();i++){
        int c=v[i];
        auto [l,r]=ranges[c];

        if(i==l){
            st.push(c);
            ans=max(ans,int(st.size()));
        }
        // if(st.empty())return 0;
        if(st.top()!=c){
            cout<<-1<<endl;
            return 0;
        }
        if(i==r)st.pop();
    }

    cout<<ans<<endl;
}

