// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
/////////////////////////////////////////////////////////// max 18 dig
int n,fp[21];

inline int f(int d){
    //cerr<<"f:"<<left<<setw(2)<<d<<"|";
    int ans=1,x=n;
    for(int i=0;d-i-1>i;i++){
        int b=fp[d-i-1]-fp[i];
        if(x/b>9)return 0;
        ans*=10-x/b-!i;
        x%=b;
        //cerr<<ans<<",";
    }
    if(x)return 0;
    if(d&1)ans*=10;
    return ans;
}

signed main(void){
    fp[0]=1;for(int i=1;i<21;i++)fp[i]=fp[i-1]*10;
    cin>>n;

    int ans=0;
    for(int i=1;i<=20;i++){
        ans+=f(i);  
        //cerr<<"|"<<ans<<endl;
    }

    cout<<ans<<endl;
}
