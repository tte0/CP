// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k,cost;
vector<int> v;
multiset<int> l,r;

signed main(void){
    cin>>n>>k;
    v.resize(n);
    for(int& i:v)cin>>i;

    if(k==1){
        for(int i=0;i<n;i++)cout<<"0 ";
        return 0;
    }

    auto balance=[&](){
        while(l.size()<r.size()){
            cost-=l.size()*(*r.begin()-*l.end());
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while(l.size()-1>r.size()){
            cost+=l.size()*(*r.begin()-*l.end());
            r.insert(*l.end());
            l.erase(l.end());
        }
    };
    
    vector<int> t(v.begin(),next(v.end(),k));
    sort(t.begin(),t.end());
    for(int i=0;i<(k+1)/2;i++)l.insert(v[i]),cost+=v[(k-1)/2]-v[i];
    for(int i=(k+1)/2;i<n;i++)r.insert(v[i]),cost+=v[i]-v[(k-1)/2];



}

