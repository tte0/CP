#include <bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    cin>>n>>m;
    vector<int> bt(n);
    
    for(int i=0;i<m;i++){
        int x;char c;
        cin>>x>>c;
        if(c=='F' || bt[x-1])cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        bt[x-1]|=(c=='M');
    }
}
