/*
Author: Teoman Ata Korkmaz
*/
//#pragma GCC target("popcnt,lzcnt")
//#pragma GCC target("abm,mmx")
//#pragma GCC target("avx,avx2")
//#pragma GCC target("bmi,bmi2,fma")
//#pragma GCC target("sse,sse2,sse3,sse4,sse4.1,sse4.2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int int32_t
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define mset(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
///////////////////////////////////////////////////////////////////
constexpr int N=1e5+5;
int n,q,x,p,dp[N];
int v[N];

signed main(void){
    for(int i=0;i<N;i++)dp[i]=INT32_MIN;
    fastio;
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    vi sorted;
    for(int i=0;i<n;i++)sorted.pb(i);
    sort(rall(sorted),[&](int a,int b){return v[a]<v[b];});
    //debug("sorted:",sorted);
    while(q--){
        cin>>p;
        if(dp[p]!=INT32_MIN){
            cout<<dp[p]<<endl;
            continue;
        }
        int sum=0;
        bitset<N> vis;
        for(int i=n-1;i>n-p;i--){
            vis[sorted[i]]=1;
            sum+=i&1?-v[sorted[i]]:v[sorted[i]];
        }
        //debug("sum:",sum);
        //debug("vis:",vis);
        priority_queue<int> st;
        for(int i=0;i<p;i++)if(!vis[i])st.push(v[i]),vis[i]=1;
        for(int round=0;round<n-p+1;round++){
            int it=st.top();
            sum+=round&1?-it:it;
            st.pop();
            if(round+p<n && !vis[round+p])st.push(v[round+p]),vis[round+p]=1;
        }
        cout<<(dp[p]=sum)<<endl;
    }
}