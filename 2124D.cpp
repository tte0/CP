// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> v;

inline void solve(void){
    cin>>n>>k;
    v.resize(n);
    for(auto& i:v)cin>>i;
    if(k<3)return void(cout<<"YES"<<endl);

    vector<int> v_sorted(v);
    sort(v_sorted.begin(),v_sorted.end());
    int kth=v_sorted[k-1];
    
    vector<int> a={0},b;
    for(auto i:v){
        if(i==kth)a.back()++;
        else if(i<kth){
            a.push_back(0);
            b.push_back(i);
        }
    }

    for(int i=0;i<b.size()/2;i++){
        if(b[i]!=b[b.size()-i-1]){
            //cerr<<"b not plaindrone";
            cout<<"NO"<<endl;
            return;
        }
    }

    int ans=b.size();
    for(int i=0;i<a.size();i++){
        ans+=min(a[i],a[a.size()-i-1]);
    }

    //cerr<<"a:";for(auto i:a)cerr<<i<<",";cerr<<endl;
    //cerr<<"b:";for(auto i:b)cerr<<i<<",";cerr<<endl;

    if(ans<k-1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
