// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,k,q,pref[N];

signed main(void){
    cin>>n>>k>>q;
    
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        pref[l]++;
        pref[r+1]--;
    }

    for(int i=1;i<N;i++)pref[i]+=pref[i-1];
    for(int i=0;i<N;i++)pref[i]=(pref[i]>=k);
    for(int i=1;i<N;i++)pref[i]+=pref[i-1];

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<endl;
    }
}
