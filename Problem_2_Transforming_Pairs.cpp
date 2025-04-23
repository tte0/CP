// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int INF=INT64_MAX;
///////////////////////////////////////////////////////////
int a,b,c,d;

inline int f(int a,int b,int c,int d){
    static int k,m;
    k=b?(c-a)/b:INF;
    m=c?(d-b)/c:INF;

    if(b==0 && c-a!=0)return INF;
    if(c==0 && d-b!=0)return INF;

    assert(k!=INF);
    assert(m!=INF);

    
}

inline void solve(void){
    cin>>a>>b>>c>>d;
    static int ans=min(f(a,b,c,d),f(b,a,d,c));
    cout<<(ans==INF?-1:ans);
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }    
}
