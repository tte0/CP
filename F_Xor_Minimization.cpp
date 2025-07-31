// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

inline int msb(int x){
    x|=(x>>1);
    x|=(x>>2);
    x|=(x>>4);
    x|=(x>>8);
    x|=(x>>16);
    return(x&~(x>>1));
}

int f(int l=0,int r=n){//[l,r)
    /*cerr<<l<<" "<<r<<endl;
    for(auto i:v)cerr<<i<<",";
    cerr<<endl<<endl;*/
    if(r-l==1)return 0;
    if(r-l==0)return 2e9;
    int b=0;
    for(int i=l;i<r;i++)b|=v[i];
    if(b==0)return 0;
    b=msb(b);

    for(int i=l;i<r;i++){
        if(v[i]&b){
            for(int j=i;j<r;j++)v[j]&=b-1;
            int ans=(i==l?0:b)+min(f(l,i),f(i,r));
            //cerr<<">>"<<l<<","<<r<<":"<<ans<<endl;
            return ans;
        }
    }
    abort();
}

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    n=v.size();

    cout<<f();
}
