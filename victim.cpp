typedef long long ll;
ll pie(ll army){return (1ll<<army);}
#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define endl '\n'
#define mid ((left+right)>>1)
const ll inf=2000000000000000005;
const int sonsuz=2000000005;
using namespace std;
ll fpow(ll x,ll y,ll m=0){if(y<0){cout<<"powError";return -1;}if(m)x%=m;ll res=1;while(y>0){if(y&1)res*=x;x*=x;if(m){x%=m;res%=m;}y>>=1;}return res;}
 
void code(){
	string a,b;cin>>a>>b;
    string c=b+"?"+a;
    int n=a.size(),m=b.size();
    int dp[n+m+1];
    dp[0]=0;
    int ans=0;
    for(int i=1;i<=n+m;i++){
        int j;
        for(j=dp[i-1];j>0;j=dp[j-1]){
            if(c[j]==c[i])
                break;
        }
        if(!j){
            dp[i]=(c[i]==c[0]);
        }
        else{
            dp[i]=j+1;
        }
        if(i>=m&&dp[i]==m){
            ans++;
        }
    }
    cout<<ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	bool usaco=0;if(usaco){freopen(".in","r",stdin);freopen(".out","w",stdout);}
	int t=1;
	if(!t)cin>>t;
	while(t--){code();cout<<endl;}
    return 0;
}