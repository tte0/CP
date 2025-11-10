// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q;
vector<tuple<int,int>> range;

inline int query(int l,int r){
    cout<<"? "<<l+1<<" "<<r+1<<endl<<flush;
    int x;
    cin>>x;
    return x;
}

inline void answer(int x){
    cout<<"! "<<x<<endl<<flush;
}

inline void solve(){
    cin>>n>>q;
    range.resize(q);
    for(auto& [a,b]:range)cin>>a>>b;
    for(auto& [a,b]:range)a--,b--;


    vector<int> max_r(n,-1),min_l(n,n);
    for(auto [l,r]:range){
        max_r[l]=max(max_r[l],r);
        min_l[r]=min(min_l[r],l);
    }

    int l=0,r=n-1;
    while(l<=r){
        if(max_r[l]==-1){
            l++;
            continue;
        }
        if(min_l[r]==n){
            r--;
            continue;
        }
        if(max_r[l]<)
    }
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;    
    while(t--)solve();
}
