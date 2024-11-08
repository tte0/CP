// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m;
string s,x,y;

inline int findsize(){
    int a=count(x.begin(),x.end(),'0');
    int b=count(x.begin(),x.end(),'1');
    int c=count(y.begin(),y.end(),'0');
    int d=count(y.begin(),y.end(),'1');
    if(b==d)return a==c?-2:-1;
    if(a<c)a*=-1,b*=-1,c*=-1,d*=-1;
    return (a-c)*n%(d-b)?-1:(a-c)*n/(d-b);  
}

inline void solve(){
    cin>>s>>x>>y;
    n=s.size();
    
    m=findsize();
    //cerr<<"m:"<<m<<endl;
    if(m==-1){
        cout<<"No"<<endl;
        return;
    }   
    if(m==-2 || m==0){
        cout<<"Yes"<<endl;
        return;
    }
    
    for(int i=max(int(0),n-m);i<n;i++){
        int j=m-n+i;
        if(n<=j)break;
        if(s[i]!=s[j]){
            cout<<"No"<<endl;
            return;
        } 
    } 

    cout<<"Yes"<<endl;
}

signed main(void){
    int t;                
    cin>>t;
    while(t--)solve();
}

