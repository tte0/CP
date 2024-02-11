#include <bits/stdc++.h>

using namespace std;

typedef long long lo;

#define fi first
#define se second
#define endl "\n"
#define int long long
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)
#define _ << " " <<

const lo inf = 1000000000;
const lo li = 500005;
const lo mod = 1000000007;

int n,m,a[li],k,flag,t,mx[li],PS[li];
int cev;
string s;
vector<int> v[li];

int32_t main(void){
	fio();
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		FOR{
            mx[i]=0;
			cin>>a[i];
			PS[i]=max(PS[i-1],a[i]);
            v[i].clear();
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
            v[x].pb(y);
			mx[y]=max(mx[y],PS[x]);
		}
		flag=0;
		FOR{
            if(a[i]==0 && mx[i]==k){cout<<"-1\n";flag=1;cerr<<mx[i]<<" "<<a[i]<<" "<<i<<endl;break;}
			if(a[i]==0)a[i]=mx[i]+1;
			else{
				if(mx[i]>=a[i]){cout<<"-1\n";flag=1;cerr<<mx[i]<<" "<<a[i]<<" "<<i<<endl;break;}
			}
            for(auto go:v[i]){
                mx[go]=max(mx[go],a[i]);
            }
		}
		if(flag)continue;
		FOR cout<<a[i]<<" ";
        cout<<endl;
	}
	return 0;
}