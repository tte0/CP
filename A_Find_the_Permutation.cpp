// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
char c;

inline void solve(void){
    cin>>n;
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(i==j)continue;
            if(c=='0'){
                cnt[max(i,j)]++;
            }
            else{
                cnt[min(i,j)]++;
            }
        }
    }

    //cerr<<"cnt:";for(auto i:cnt)cerr<<i<<",";cerr<<endl;

    for(int a=2*(n-1);a>=0;a-=2){
        for(int i=0;i<n;i++){
            if(cnt[i]==a){
                cout<<i+1<<" ";
                break;
            }
        }
    }

    cout<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
