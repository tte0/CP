#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=401000;
int n,m,a[N];
int main() {
    freopen("correct_output.txt","w",stdout);freopen("testcase.in","r",stdin);
	scanf("%d%d",&n,&m);
	int s=0;
	rep(i,0,2*n) scanf("%d",a+i),s=(s+a[i])%m;
	sort(a,a+2*n);
	if (m%2==1) {
		bool sm=1;
		rep(i,0,2*n) sm&=(a[i]==a[i^1]);
		puts(sm?"Bob":"Alice");
	} else {
		if (s%2!=0) puts("Alice");
		else {
			int par=0;
			rep(i,0,2*n) par^=(a[i]<m/2),a[i]%=m/2;
			sort(a,a+2*n);
			bool sm=1;
			rep(i,0,2*n) sm&=a[i]==a[i^1];
			puts(sm&&(par==0)?"Bob":"Alice");
		}
	}
}