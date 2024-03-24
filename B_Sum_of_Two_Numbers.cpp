#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define print(x) cout<<x<<endl
#define printInline(x) cout<<x<<" "
 
#define ll long long
#define lli long long int
 
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<long long,long long>>
 
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define popb pop_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
 
const int inf = 1e9;
const int mod = 1e9+7;
 
int digit_sum(int n) {
	int sum = 0;
	while (n>0) {
		sum+=n%10;
		n=n/10;
	}
	return sum;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin>>t;
 
    while(t--) {
    	int n;
    	cin>>n;
 
    	if(n==1) {
    		cout<<"1 0"<<endl;
    		continue;
    	}
    	int low=1;
    	int high=n-1;
 
    	while(low<=high) {
    		int mid=(low+high)/2;
    		int x=mid;
    		int y=n-x;
    		int diff=abs(digit_sum(x)-digit_sum(y));
    		if(diff==0 || diff==1) {
    			cout<<x<<" "<<y<<endl;
    			break;
    		}
    		else if(digit_sum(x)>digit_sum(y)) {
    			high =mid-1;
    		}
    		else {
    			low=mid+1;
    		}
    	}
    }
	
	return 0;    
}