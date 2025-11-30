// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=1e5;
///////////////////////////////////////////////////////////
int n,ans[N];
vector<int> v,arr[N];

inline int solve(int c,int x){

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

    for(int x=1;)
}
