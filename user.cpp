#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin() , v.end()
#define sz(a) (int)a.size()
using namespace std;

void _(){
  int n;
  cin >> n;
  int ans=0,cur=0;
  int ar[n+5];
  for(int i=1;i<=n;i++) cin >> ar[i];

  set<array<int,2>> s;

  auto Remove = [&](array<int,2> u){
  	if(!s.count(u)) return;
    auto it = s.lower_bound(u);
    s.erase(*it);
    array<int,2> l={-1,-1},r={-1,-1};
    it = s.lower_bound(u);
    if(it!=s.end()) r = *it;
    if(it!=s.begin()) l = *(--it);
    if(r!=array<int,2>{-1,-1}) cur -= r[0] * (r[1] - u[1]);
    if(l!=array<int,2>{-1,-1}) cur -= u[0] * (u[1] - l[1]);
    if(l!=array<int,2>{-1,-1} && r!=array<int,2>{-1,-1}) cur += r[0] * (r[1] - l[1]);
  };


  auto Add = [&](array<int,2> u){
    auto it = s.lower_bound(u);
    if(it!=s.begin()){
      auto it2 = it;
      it2--;
      if((*it2)[1] >= u[1]) return;
    }
    while(it != s.end() && u[1] >= (*it)[1]){
      Remove((*it));
      it = s.lower_bound(u);
    }
    array<int,2> l={-1,-1},r={-1,-1};
    it = s.lower_bound(u);
    if(it!=s.end()) r = *it;
    if(it!=s.begin()) l = *(--it);
    if(l!=array<int,2>{-1,-1} && r!=array<int,2>{-1,-1}) cur -= r[0] * (r[1] - l[1]);
    if(r!=array<int,2>{-1,-1}) cur += r[0] * (r[1] - u[1]);
    if(l!=array<int,2>{-1,-1}) cur += u[0] * (u[1] - l[1]);
    s.insert(u);
  };

  queue<int> q[n+5];
  for(int i=1;i<=n;i++){
    if(ar[i]>=n) continue;
    q[ar[i]].push(i);
  }

  for(int i=n;i>=0;i--){
    if(q[i].empty()) Add({i,n+1}); 
    else Add({i,q[i].front()});
  }
  
  for(int i=1;i<=n;i++){
    //for(auto x : s) cout << x[0] << ' ' << x[1] << '\n';
  	//cout << "hm: " << i << ' ' << cur << '\n';
    ans += cur;
    if(ar[i] >= n) continue;
    Remove({ar[i],i});
    q[ar[i]].pop();
    if(q[ar[i]].empty()) Add({ar[i],n+1});
    else Add({ar[i],q[ar[i]].front()});
  }
  
  cout << ans << '\n';
}

int32_t main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int tc=1;//cin >> tc;
  while(tc--) _();
  return 0;
}