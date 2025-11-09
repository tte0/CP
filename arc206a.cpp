// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e6+6;
///////////////////////////////////////////////////////////
int n,cnt[N];
vector<int> v;

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    v.resize(n);
    for(int& i:v)cin>>i;
    
    /*vector<int> t={v[0]};
    for(int i=1;i<n;i++){
        if(v[i]!=t.back())t.push_back(v[i]);
    }
    swap(t,v);
    n=v.size();*/
    //cerr<<"v: ";for(auto i:v)cerr<<i<<" ";cerr<<endl;

    int ans=1,c=0;
    for(int i=0;i<n;i++){
        ans+=c-cnt[v[i]];
        c++;
        if(v[i-1]!=v[i])cnt[v[i]]++;
        while(i<n-1 && v[i]==v[i+1])i++;

        //cerr<<ans<<endl;
    }

    cout<<ans<<endl;
}
