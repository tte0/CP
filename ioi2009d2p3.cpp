// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;

///////////////////////////////////////////////////////////
int n,r,q;
vector<int> h,p,adj[N];

signed main(void){
    cin>>n>>r>>q;
    h.resize(n);
    p.resize(n,0);
    for(int i=0;i<n;i++){
        if(i)cin>>p[i];
        cin>>h[i];
        p[i]--,h[i]--;
    }

    
}

