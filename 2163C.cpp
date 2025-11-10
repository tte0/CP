// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> a,b;

inline void solve(){
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    vector<int> mina,maxa,minb,maxb;
    mina=maxa=a;
    minb=maxb=b;

    for(int i=1;i<n;i++){
        mina[i]=min(mina[i],mina[i-1]);
        maxa[i]=max(maxa[i],maxa[i-1]);
    }
    for(int i=n-1;i--;){
        minb[i]=min(minb[i],minb[i+1]);
        maxb[i]=max(maxb[i],maxb[i+1]);
    }

    /*cerr<<"mina: ";for(auto i:mina)cerr<<i<<",";cerr<<endl;
    cerr<<"minb: ";for(auto i:minb)cerr<<i<<",";cerr<<endl;
    cerr<<"maxa: ";for(auto i:maxa)cerr<<i<<",";cerr<<endl;
    cerr<<"maxb: ";for(auto i:maxb)cerr<<i<<",";cerr<<endl;*/

    vector<int> fol(2*n+1,2*n+1);
    for(int i=0;i<n;i++){
        fol[min(mina[i],minb[i])]=min(fol[min(mina[i],minb[i])],max(maxa[i],maxb[i]));
    }
    for(int i=fol.size()-1;i--;)fol[i]=min(fol[i],fol[i+1]);
    //cerr<<"fol: ";for(auto i:fol)cerr<<i<<",";cerr<<endl;
    int ans=0;
    for(int i=1;i<=2*n;i++){
        ans+=2*n-fol[i]+1;
    }

    cout<<ans<<endl;
    cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
