// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e3+3;
///////////////////////////////////////////////////////////
int n,arr[N][N],to[2*N],riyal_cnt[2*N];
vector<int> cnt[2*N];

signed main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            riyal_cnt[arr[i][j]]++;
        }
    }

    for(int i=2*n;i>=2;i--){
        cnt[-abs(i-n-1)+n].push_back(i);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(to[arr[i][j]])continue;
            to[arr[i][j]]=cnt[riyal_cnt[arr[i][j]]].back();
            cnt[riyal_cnt[arr[i][j]]].pop_back();
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<to[arr[i][j]]<<" ";
        }
        cout<<endl;
    }
}
