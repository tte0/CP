// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v,comp;

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    comp=v;
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());

    for(auto& i:v)i=lower_bound(comp.begin(),comp.end(),i)-comp.begin();

    vector<int> last(n,-1);
    int ans=0,add=0;
    for(int i=0;i<n;i++){
        add+=i-last[v[i]];
        ans+=add;
        last[v[i]]=i;
    }

    cout<<ans<<endl;
}
