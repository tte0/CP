// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
string s;

signed main(void){
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        cnt+=(s[i]=='('?1:-1);
        if(cnt<0){
            cout<<"No"<<endl;
            return 0;
        }
    }    
    cout<<(s.size()&1?"No":"Yes")<<endl;
}
