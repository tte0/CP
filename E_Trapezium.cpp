// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<tuple<int,int>> p;

pair<int,int> slope(int i,int j){
    auto [xi,yi]=p[i];
    auto [xj,yj]=p[j];
    int x=xi-xj,y=yi-yj;
    int g=__gcd(x,y);
    return {x/g,y/g};
}

signed main(void){
    cin>>n;
    p.resize(n);
    for(auto& [x,y]:p)cin>>x>>y;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cerr<<(i==j?31:(slope(i,j).first))<<","<<(i==j?31:(slope(i,j).second))<<endl;
        }
        cerr<<endl;
    }
}
