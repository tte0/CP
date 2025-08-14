// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;

inline void solve(void){
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"mul 999999999"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"digit"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(n!=81){
        cout<<"add "<<n-81<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"!"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
