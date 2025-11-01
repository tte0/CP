// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int c,x;

inline int msb(int x){
    x|=x>>1;
    x|=x>>2;
    x|=x>>4;
    x|=x>>8;
    x|=x>>16;
    return (x+1)>>1;
}

inline void solve(){
    cin>>c>>x;

    if(x<(x^c)){
        cout<<(c^x)<<endl;
        return;
    }
    if(c==x){
        cout<<2*msb(c)<<endl;
        return;
    }

    int n=(1LL<<50)+(c-x)/2;
    if((n^c)%n==x){
        cout<<n<<endl;
        return;
    }
    cout<<-1<<endl;
}

inline void brute_force(){
    int _=1<<5;
    for(int c=1;c<_;c++){
        for(int x=1;x<_;x++){
            bool flag=0;
            for(int n=1;n<(_<<1);n++){
                if(!(x<(x^c) || c==x) && (n^c)%n==x){
                    cerr<<"idiot: n="<<n<<",c="<<c<<",x="<<x<<endl;
                    flag=1;
                }
            }
            if(flag)cerr<<endl;
        }
    }
}

signed main(void){
    //brute_force();

    int t;
    cin>>t;
    while(t--)solve();
}
