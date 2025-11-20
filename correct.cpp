#include <bits/stdc++.h>
using namespace std;
//~ #define int long long
#define pb push_back
#define emb emplace_back
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define sp << " " <<
#define N 300000
#define inf (int)1e9
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

int n;
ii st[2*N];
void update(int x,int val){
	st[x+n]={val,x};
	for(x=(x+n)>>1;x;x>>=1)
		st[x]=max(st[x<<1],st[x<<1|1]);
}
int query(int l,int r){
	ii ans={0,-1};
	for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
		if(l&1) ans=max(ans,st[l++]);
		if(r&1) ans=max(ans,st[--r]);
	}
	return ans.sc;
}
void solve(){
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		update(i,a[i]);
	}
	set<ii> s;
	s.insert({0,-n});
	for(int i=0;i<n;i++)
		s.insert({a[i],-i});
	int ans=0,l=0;
	for(int i=0;i<n;i++){
		while(l<=i)
			s.erase({a[l],-l}),l++;
		ans++;
		int j=-(--s.lower_bound({a[i],-n}))->sc;
        cerr<<"i,j: "<<i<<","<<j<<endl;
		i=query(i,j-1);
	}
	cout << ans << "\n";
}
int32_t main(){
	//~ freopen("hopscotch.in","r",stdin);
	//~ freopen("hopscotch.out","w",stdout);
	
	cout << fixed << setprecision(0);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int test=1;
	//~ cin >> test;
	while(test--) solve();
}
