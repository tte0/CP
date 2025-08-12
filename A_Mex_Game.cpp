// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
string s;

signed main(void){
    cin>>n>>s;

    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(s[i]=='B');
        if(cnt==i/2+1){
            cout<<(s[i+1]=='A'?"Alice":"Bob")<<endl;
        }
        else if(cnt<i/2+1){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
}
