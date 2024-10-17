// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m,k,ans;
vector<pair<int,int>> v;
signed main(void){
    cin>>n>>m>>k;
    v.resize(n);
    for(auto& [w,a]:v)cin>>w>>a;

    sort(v.rbegin(),v.rend());
    deque<pair<int,int>> q;//w,a
    q.push_back({1e18+18,m});

    for(auto [w,a]:v){
        //cerr<<"w,a: "<<w<<","<<a<<endl;
        int cnt=0;
        while(cnt<a && q.size() && w+k<=q.front().first){
            auto& [qw,qa]=q.front();
            //cerr<<"qw,qa: "<<qw<<","<<qa<<endl;
            if(a-cnt>=qa){
                cnt+=qa;
                q.pop_front();
            }
            else{
                qa-=a-cnt;
                cnt=a;
            }
        }
        ans+=cnt;
        if(cnt){
            q.push_back({w,cnt});
        }
    }

    cout<<ans<<endl;
}
