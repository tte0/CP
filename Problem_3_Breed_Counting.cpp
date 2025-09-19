// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q;
vector<vector<int>> v(3,{0});

signed main(void){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[0].push_back(v[0].back());
        v[1].push_back(v[1].back());
        v[2].push_back(v[2].back());
        v[x-1].back()++;
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<v[0][y]-v[0][x-1]<<" "<<v[1][y]-v[1][x-1]<<" "<<v[2][y]-v[2][x-1]<<endl;
    }
}
