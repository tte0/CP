// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;
vector<int> a,b;

inline void solve(){
    cin>>n>>k;
    a.resize(n);
    b.resize(n);
    for(int& i:a)cin>>i;
    for(int& i:b)cin>>i;

    if(a==b){
        cout<<"Yes"<<endl;
        return;
    }

    if(k==1){
        vector<int> new_b={b[0]},new_a={a[0]};
        for(auto i:b)
            if(new_b.back()!=i)
                new_b.push_back(i);
        for(auto i:a)
            if(new_a.back()!=i)
                new_a.push_back(i);
        swap(a,new_a);
        swap(b,new_b);

        int n=a.size(),m=b.size(),pa=0,pb=0;
        for(pa=pb=0;pa<n && pb<m;pa++){
            if(a[pa]==b[pb])pb++;
        }
        
        cout<<((pb==m)?"Yes":"No")<<endl;
    }
    else{
        vector<int> x(n+1),y(n+1);
        bool flag=1; 
        for(int i=0;i<n;i++){
            if(x[b[i]])flag=0;
            x[b[i]]++;
            if(0<=i-k)x[b[i-k]]--;
        }

        x.assign(n+1,0);
        for(auto i:a)x[i]++;
        for(auto i:b)y[i]++;
        for(int i=0;i<=n;i++){
            if(y[i] && !x[i]){
                flag=1;
                break;
            }
        }

        cout<<(flag?"No":"Yes")<<endl;
    }
}

signed main(void){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

