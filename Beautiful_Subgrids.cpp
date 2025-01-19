// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native,popcnt")
#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////////////////////////
int n;
long long ans;
string s;
bitset<3000> bt[3000];

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x=(bt[i]&bt[j]).count();
            ans+=x*(x-1)/2;
        }
    }

    cout<<ans<<"\n";
}
