// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
random_device rd;
mt19937 mt(rd());
///////////////////////////////////////////////////////////
int n;
vector<int> cur_ind,cur_val;

inline bool query(int i,int x){
    cout<<"? "<<i<<" "<<x<<endl<<flush;
    int ans;
    cin>>ans;
    if(ans==-1){
        exit(0);
    }
    assert(ans==0 || ans==1);
    return ans;
}

inline void answer(int x){
    cout<<"! "<<x<<endl<<flush;
}

inline int f(int bit){
    assert(cur_ind.size());
    assert(cur_ind.size()==cur_val.size());
    if()
}

inline void solve(){
    cin>>n;
    cur_ind.resize(n);
    cur_val.resize(n);
    iota(cur_ind.begin(),cur_ind.end(),1);
    iota(cur_val.begin(),cur_val.end(),1);

    answer(f(0));
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}
