/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
int n;
vector<string> s;

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    s.resize(n);
    for(string& i:s)cin>>i;

    for(string& i:s)cerr<<i<<endl;
    cerr<<endl;
    
    for(int i=0;i<n/2;i++){
        for(int j=0;2*(i+j)<n-1;j++){
            int a=i;
            int b=(n-1)-i;
            if(i%4==0){
                swap(s[b-j][a ],s[b-j][b]);
                swap(s[b-j][b],s[b][a]);
                swap(s[b][a],s[b][b]);
            }
            else if(i%4==1){
                swap(s[a][b],s[b][a]);
                swap(s[a][a],s[b][b]);
            }
            else if(i%4==2){
                swap(s[b][a],s[b][b]);
                swap(s[a][a],s[b][a]);
                swap(s[a][b],s[a][a]);
            }
        }
        for(string& i:s)cerr<<i<<endl;
        cerr<<endl;
    }

    for(string& i:s)cout<<i<<endl;
}
