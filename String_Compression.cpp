// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
string s;

string transform(string s){
    int n=s.size();
    stringstream ans;
    int last=0;
    for(int i=1;i<n;i++){
        if(s[i-1]!=s[i]){
            ans<<s[i-1];
            if(i-last>1)ans<<(i-last);
            last=i;
        }
    }
    ans<<s[n-1];
    if(n-last>1)ans<<(n-last);

    return ans.str();
}

signed main(void){
    cin>>n>>s;

    while(true){
        string t=transform(s);
        if(t==s)break;
        s=t;
    }

    cout<<s<<endl;
}
