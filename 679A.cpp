// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int primes[19]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};

inline bool query(int x){
    cout<<x<<endl<<flush;
    static string s;
    cin>>s;
    return s=="yes";
}

signed main(void){
    int ans=0;
    for(int i=0;i<19;i++)ans+=query(primes[i]);
    cout<<(ans>1?"composite":"prime")<<endl;
}
