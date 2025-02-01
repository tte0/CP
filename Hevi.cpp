#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n,sub[li],dep[li],tin[li],sayac,par[li];

inline void pre(int node,int ata){
	sub[node]=1;
	par[node]=ata;
	dep[node]=dep[ata+1];
	for(auto go:v[node]){
		if(go==ata)continue;
		pre(go,node);
		sub[node]+=sub[go];
	}
}

inline void dfs(int node,int ata){
	int mxsiz=0,ind=0;
	tin[node]=++sayac;
	for(auto go:v[node]){
		if(go==ata)continue;
		if(sub[go]>mxsiz){
			ind=go;
			mxsiz=sub[go];
		}
	}
	if(ind){
		root[ind]=root[node];//heavy chain
		dfs(ind,node);
	}
	for(auto go:v[node]){
		if(go==ata || go==ind)continue;
		root[go]=go;
		dfs(go,node);
	}
}

inline int ask(int x,int y){
	int cevap=0;
	while(x!=y){
		if(dep[x]<dep[y]){
			swap(x,y);
		}//x daha asagida
		if(root[x]==root[y]){
			cevap+=query(1,1,n,tin[y],tin[x]);
			 break;
		}
		cevap+=query(1,1,n,tin[root[x]],tin[x]);
		x=par[root[x]];
	}
	return cevap;
}

int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
}
