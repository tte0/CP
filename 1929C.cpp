#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#define ll long long
#include<string>
using namespace std;
ll max(ll a,ll b){return (a>b)?a:b;}
ll min(ll a,ll b){return (a<b)?a:b;}
void sol(){
	ll k,x,a;cin>>k>>x>>a;
	ll y=0,s=0;
	ll hh=0;
	for(ll i=0;i<=x;i++){
		ll z=y/(k-1) +1;
		y+=z;
		if(y>10000000000){hh++;break;}
	}
	if(y>a||hh)cout<<"NO\n";
	else cout<<"YES\n";
}
int main()
{
	ll t;cin>>t;
	while(t--)sol();
}