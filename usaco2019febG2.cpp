// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=100005;
///////////////////////////////////////////////////////////
int n;
vector<int> v;
stack<int> st[N];

signed main(void){
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    cin>>n;

    int mx=-1;
    vector<int> ind(n,-1);
    for(int i=0;i<n;i++){
        int x;cin>>x;x--;

        if(mx>x){
            cout<<i<<endl;
            return 0;
        }

        for(int j=x;j>=0 && ind[j]==-1;j--){
            ind[j]=x;
        }

        while(st[ind[x]].size() && st[ind[x]].top()<x){
            mx=max(mx,st[ind[x]].top());
            st[ind[x]].pop();
        }

        st[ind[x]].push(x);
    }

    cout<<n<<endl;
}

