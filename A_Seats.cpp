/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
int n;
string s;

signed main(void){
    cin>>n>>s;
    int cnt=0;
    for(int i=1;i<n-1;i++){
        if(s[i-1]=='#' && s[i]=='.' && s[i+1]=='#')cnt++;
    }
    cout<<cnt<<endl;
}
