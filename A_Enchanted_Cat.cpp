// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
using namespace std;
#define int int64_t
//////////////////////////////////////////////////////////
int n,k;

signed main(void){
    cin>>n>>k;
    int l=powl(10,n-1),r=powl(10,n);
    //cerr<<l<<","<<r<<endl;
    r--;
    if(l==1)l--;
    //cerr<<l<<","<<r<<endl;
    if(l%(1LL<<k)!=0){
        //cerr<<"lower l"<<endl;
        l>>=k;
        l++;
        l<<=k;
    }
    cerr<<l<<","<<r<<endl;
    if(r%(1LL<<k)!=0){
        //cerr<<"lower r"<<endl;
        r>>=k;
        r<<=k;
    }
    //cerr<<l<<","<<r<<endl;
    cout<<(r-l)/(1LL<<k)+1<<endl;
}
