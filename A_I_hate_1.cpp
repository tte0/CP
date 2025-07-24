// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n;
bitset<N> bt;
vector<int> v;

signed main(void){
    cin>>n;
    if(n==1){
        cout<<"1\n1";
        return 0;
    }
    for(int i=n-(n&1);i>0;i--){
        if(bt[i])continue;
        v.push_back(i);
        int x=i-1;
        for(int j=1;j<=sqrt(x);j++){
            if(x%j==0)bt[j]=bt[x/j]=true;
        }
    }

    cout<<v.size()<<endl;
    for(auto i:v)cout<<i<<" ";
}
