// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=10;
///////////////////////////////////////////////////////////
int n,k,pref[N][N];

signed main(void){
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        pref[xa][ya]++;
        pref[xb][ya]--;
        pref[xa][yb]--;
        pref[xb][yb]++;
    }    
    
    for(int i=0;i<N;i++){
        cerr<<"pref: ";
        for(int j=0;j<N;j++){
            if(i)
                pref[i][j]+=pref[i-1][j];
            if(j)
                pref[i][j]+=pref[i][j-1];
            if(i&&j)
                pref[i][j]-=pref[i-1][j-1];
            cerr<<pref[i][j]<<",";
        }
        cerr<<endl;
    }


    int ans=0;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            ans+=(pref[i][j]==k);
        }
    }

    cout<<ans<<endl;
}
