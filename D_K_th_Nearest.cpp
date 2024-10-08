/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h> 
using namespace std;
int n,q,b,k;
vector<int> a;

inline int count(int x){//[-1e8,x)
    int l=0,r=n;
    while(l<r){
        int m=l+r>>1;
        if(a[m]<x)l=m+1;
        else r=m;
    }
    return l;
}

int main(void){
    cin>>n>>q;
    a.resize(n);
    for(int& i:a)cin>>i;
    sort(a.begin(),a.end());

    while(q--){
        cin>>b>>k;
        int l=0,r=2e8+8;
        while(l<r){
            int m=l+r>>1;
            if(count(b+m+1)-count(b-m)<k)l=m+1;
            else r=m;
        }
        cout<<l<<endl;
    }
}
