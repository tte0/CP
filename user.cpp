#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define fr first
#define sc second
#define endl '\n'
using namespace std;

const int mod=1e9+7;

int sum(int x,int y){
	if(x+y<mod)return x+y;
	return x+y-mod;
}

int sub(int x,int y){
	if(y)y=mod-y;
	return sum(x,y);
}

int mul(ll x,ll y){
	return (x*y)%mod;
}

int pref[800023];

int tree[800023],lazy[800023];
int l,r=2e5;
#define mid ((left+right)>>1)
void push(int node,int left,int right){
	if(lazy[node]==0)return;
	tree[node]=sum(tree[node],mul(lazy[node],sub(pref[right],pref[left-1])));
	if(left!=right){
		lazy[node*2]=sum(lazy[node*2],lazy[node]);
		lazy[node*2+1]=sum(lazy[node*2+1],lazy[node]);
	}
	lazy[node]=0;
}

int query(int node=1,int left=0,int right=2e5){
	if(left>r||right<l)return 0;
	push(node,left,right);
	if(left>=l&&right<=r)return tree[node];
	return sum(query(node*2,left,mid),query(node*2+1,mid+1,right));
}

void update(int node=1,int left=0,int right=2e5){
	if(left>=l&&right<=r){
		lazy[node]=sum(lazy[node],1);
		push(node,left,right);
		return;
	}
	push(node,left,right);
	if(left>r||right<l)return;
	update(node*2,left,mid);update(node*2+1,mid+1,right);
	tree[node]=sum(tree[node*2],tree[node*2+1]);;
}

int main(){
	ios_base::sync_with_stdio(23-23);cin.tie(NULL);
	for(int i=1;i<=2e5;i++){
		pref[i]=sum(pref[i-1],i);
	}
	int q;cin>>q;
	int ans=0;
	update();
	while(q--){
		cin>>l>>r;
		ans=sum(ans,query());
		update();
		update();
		cout<<ans<<endl;
	}
}