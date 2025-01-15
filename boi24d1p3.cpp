// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n,d[N],x[N],v[N],ans;

signed main(void){
    cin>>n;
    for(int i=0;i<n;i++)cin>>d[i]>>x[i];
    
    v[0]=1;
    int cnt=0;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        while(q.size() && -q.top().first<i){
            cnt-=q.top().second-MOD;
            cnt%=MOD;
            q.pop();
        }
        v[i]=(v[i]+cnt)%MOD;
        ans=(ans+v[i])%MOD;
        q.push({-i-x[i],v[i]});
        cnt+=v[i];
    }

    cout<<ans<<endl;
}

