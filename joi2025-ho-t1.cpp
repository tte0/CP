// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,ans;
vector<int> a,b,comp;
map<int,int> mp;

signed main(void){
    cin>>n;
    a.resize(n);    
    b.resize(n);    

    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    for(auto i:a)comp.push_back(i);
    for(auto i:b)comp.push_back(i);
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());

    int p1=1,p2=1,last=0;
    for(int i=0;i<comp.size();i++){
        int x=comp[i];
        while(p1<n && a[p1]<=x)p1++;
        while(p2<n && b[p2]<=x)p2++;
        mp[x]=(p1-1)*(p2-1)-last;
        last=(p1-1)*(p2-1);
    }

    for(int i=1;i<n;i++)mp[a[i]]++;
    for(int i=1;i<n;i++)mp[b[i]]++;

    mp[a[0]]++;

    int ans=-1,val=-1;
    for(auto [key,cnt]:mp){
        if(cnt>=ans){
            ans=cnt;
            val=key;
        }
    }

    cout<<val<<" "<<ans<<endl;
}
