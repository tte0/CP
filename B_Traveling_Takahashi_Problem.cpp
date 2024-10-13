/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
int n,x1,yy1,x2,y2;
long double ans;

signed main(void){
    cout<<fixed<<setprecision(6);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x2>>y2;
        ans+=sqrtl((x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2));
        x1=x2;
        yy1=y2;
    }
    ans+=sqrtl(x2*x2+y2*y2);
    cout<<ans<<endl;
}
