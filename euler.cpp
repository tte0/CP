// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////

signed main(void){
    int sum=0;
    for(int i=1;i<=1000;i++){
        if(i%3==0 || i%5==0)sum+=i;
    }
    cout<<sum<<endl;
}
