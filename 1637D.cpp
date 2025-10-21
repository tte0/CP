// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=103;
///////////////////////////////////////////////////////////
int n;
bool dp[N][N*N];
vector<int> a,b;

inline void solve(){
    memset(dp,0,sizeof(dp));
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    if(n==1){
        cout<<"0\n";
        return;
    }

    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int diff=0;diff<=i*100;diff++){
            dp[i+1][abs(diff+(a[i]-b[i]))]|=dp[i][diff];
            dp[i+1][abs(diff-(a[i]-b[i]))]|=dp[i][diff];
        }
    }

    int diff;
    for(diff=0;diff<N*N;diff++){
        if(dp[n][diff])break;
    }

    int ans=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]+b[i];
        ans+=a[i]*a[i]+b[i]*b[i];
    }
    ans*=n-2;
    int sum_a=(sum-diff)/2,sum_b=(sum+diff)/2;
    ans+=(sum_a*sum_a+sum_b*sum_b);

    cout<<ans<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
