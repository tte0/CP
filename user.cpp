#pragma GCC optimize ("Ofast,unroll-loops")
//~ #pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
#define fast ios::base_sync_witt_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileio freopen("user_output.txt","w",stdout);freopen("testcase.in","r",stdin)
#define first fi
#define se second
#define pb push_back
#define endl "\n"
#define int long long
typedef long long ll;

using namespace std;
vector<vector<int>> graph;
int val[200005], depth[200005], sz[200005], lca[200005][20], grp[200005], frst[200005], lst[200005], ind[200005], unind[200005];
int n, no=1, group=1, q;
vector<int> ST[200005];
int dfsdepth(int node, int par, int d){
	depth[node] = d;
	int s = 1;
	for(auto it: graph[node]){
		if(it == par){
			continue;
		}
 		s+=dfsdepth(it, node, d+1);
	}
	sz[node] = s;
	return s;
}
void dfslca(int node, int par){
	lca[node][0] = par;
	for(int i=1;i<=19;i++){
		lca[node][i] = lca[lca[node][i-1]][i-1];
	}
	for(auto it: graph[node]){
		if(it == par)continue;
		dfslca(it, node);
	}
}
int go(int node, int d){
	for(int i=0;i<=19;i++){
		if((1<<i) & d)node = lca[node][i];
	}
	return node;
}
int LCA(int node1, int node2){
	if(depth[node1]<depth[node2]){
		int temp= node1;
		node1 = node2;
		node2 = temp;
	}
	int dif = depth[node1] - depth[node2];
	node1 = go(node1, dif);
	if(node1 == node2) return node1;
	int ans = 0;
	for (int i = 19;i>=0; i--){
		if(lca[node1][i] == lca[node2][i]){
			ans = lca[node1][i];
		}
		else{
			node1 = lca[node1][i], node2 = lca[node2][i];
		}
	}
	//~ int l = 1, r = depth[node1];
	//~ while(l<=r){
		//~ int m =(l+r)/2;
		//~ if( go(node1, m) == go(node2, m)){
			//~ r = m-1;
		//~ }
		//~ else l = m+1;
	//~ }
	//~ if(node1 == node2)return node1;
	//~ else return lca[node1][0];
	return ans;
}	
void dfsgrp(int node, int par, bool c){
	ind[node] = no;
	unind[ind[node]] = node;
	grp[ind[node]] = group;
	if(c)frst[group] = ind[node];
	bool b = false;
	bool control = true;
	for(auto it: graph[node]){
		if(it == par)continue;
		if(b){
			group++;
			b = true;
		}
		//~ cout<<it<<" :: "<<node<<" :: "<<group<<" :: "<<b<<" :: "<<endl;
		control = false;
		no++;
		dfsgrp(it, node, b);
		b = true;
	}
	if(control){
		lst[grp[ind[node]]] = ind[node];
	}
}
void init(int ind, int l, int r, int g){
	if(l==r){
		ST[g][ind] = val[unind[l+frst[g]-1]];
		return;
	}
	int m= (l+r)/2;
	init(ind*2, l, m, g);
	init(ind*2+1, m+1, r, g);
	ST[g][ind] = max(ST[g][ind*2], ST[g][ind*2+1]);
}
void update(int	ind, int l, int r, int v, int u, int g){
	if(v<l || v>r){
		return;
	}
	if(l==r){
		ST[g][ind] = u;
		return;
	}
	int m = (l+r)/2;
	update(ind*2, l, m, v, u, g);
	update(ind*2+1, m+1, r, v, u, g);
	ST[g][ind]= max(ST[g][ind*2], ST[g][ind*2+1]);
}
int query(int ind, int l, int r, int s, int f, int g){
	if(l>f || r<s){
		return -1000000000;
	}
	if(l>=s && r<=f){
		return ST[g][ind];
	}
	int m= (l+r)/2;
	return max(query(ind*2, l, m, s, f, g), query(ind*2+1, m+1, r, s, f, g));
}
int adapt(int a, int b, int c){
	int ans = -1000000000;
	int g = grp[a];
	while(g != grp[c]){
		ans = max(ans, query(1, 1, lst[g]-frst[g]+1, 1, a-frst[g]+1, g));
		//~ cout <<":"<< ans << endl;
		a = ind[lca[unind[frst[g]]][0]];
		g = grp[a];
	}
	ans = max(ans, query(1, 1, lst[g]-frst[g]+1, c-frst[g]+1, a-frst[g]+1, g));
	//~ ans = max(ans, query(1, 1, lst[g]-frst[g]+1, a-frst[g]+1, c-frst[g]+1, g));
	//~ cout <<"::"<< ans << endl;
	g = grp[b];
	while(g != grp[c]){
		ans = max(ans, query(1, 1, lst[g]-frst[g]+1, 1, b-frst[g]+1, g));
		//~ cout <<":::"<< ans << endl;
		b = lca[unind[frst[g]]][0];
		b = ind[b];
		g = grp[b];
	}
	ans = max(ans, query(1, 1, lst[g]-frst[g]+1, c-frst[g]+1, b-frst[g]+1, g));
	//~ ans = max(ans, query(1, 1, lst[g]-frst[g]+1, b-frst[g]+1, c-frst[g]+1, g));
	//~ cout <<"::::"<< ans << " :: " << g<< " :: "<< grp[c]<<endl;
	return ans;
}
int32_t main(){
    fileio;
	cin>>n>>q;
	graph.assign(n+5, vector<int>());
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<n;i++){
		int a, b;
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	dfsdepth(1, 1, 0);
	for(int i=1;i<=n;i++){
		vector<pair<int, int>> v;
		for(auto it: graph[i]){
			v.pb({sz[it], it});
		}
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		graph[i].clear();
		for(auto it: v){
			graph[i].pb(it.se);
		}
		v.clear();
	}
	dfslca(1, 1);
	dfsgrp(1, 1, true);
	//~ for(int i=1;i<=n;i++){
		//~ cout<<ind[i]<<" :: "<<i<<endl;
	//~ }
	//~ for(int i=1;i<=n;i++){
		//~ cout<<unind[i]<<" :: "<<i<<endl;
	//~ }
	//~ for(int i=1;i<=n;i++){
		//~ cout<<grp[i]<<" :: "<<i<<endl;
	//~ }
	for(int i=1;i<=group;i++){
		ST[i].assign(4*(lst[i]-frst[i]+1)+5, 0);
		init(1, 1, lst[i]-frst[i]+1, i);
	}
	while(q--){
		int x;
		cin>>x;
		if(x==1){
			//update
			int y, z;
			cin>>y>>z;
			y= ind[y];
			int t = grp[y];
			update(1, 1, lst[t]-frst[t]+1, y, z, t);
		}
		else{
			//query
			int a, b;
			cin>>a>>b;
			int c = LCA(a, b);
			//~ cout<<"dırırın dırırın"<<endl;
			//~ cout<<a<<" :: "<<b<<" :: "<<c<<endl;
			//~ cout<<query(1, 1, n, ind[4], ind[5], grp[ind[4]];
			cout<< 	adapt(ind[a], ind[b], ind[c])<<" ";
		}
	}
	cout<<endl;
	return 0;
	//~ cout<<" debug "<<endl;
}	
//~ 4 1
//~ 3 4 10 7
//~ 1 2
//~ 2 3
//~ 1 4
//~ 2 2 4
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
