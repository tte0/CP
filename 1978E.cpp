// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q;
string a,b;

inline bool check(int left,int i,int right){
    i--;
    if(a[i]=='1')return true;
    if(left==0 || right==0)return false;
    if(b[i-1]=='1' && b[i+1]=='1')return true;
    if(b[i-1]=='0'){
        if(left==1)return false;
        if(a[i-2]=='1')return false;
    }
    if(b[i+1]=='0'){
        if(right==1)return false;
        if(a[i+2]=='1')return false;
    }
    return true;
}

inline int brute_force(string a,string b){
    for(int i=0;i<int(a.size())-2;i++){
        //cerr<<i;
        if(a[i]=='0' && a[i+2]=='0')b[i+1]='1';
    }
    for(int i=0;i<int(a.size())-2;i++){
        if(b[i]=='1' && b[i+2]=='1')a[i+1]='1';
    }
    return count(a.begin(),a.end(),'1');
}

inline void solve(){
    cin>>n>>a>>b>>q;

    vector<int> p(n+1);
    for(int i=2;i<=n;i++){
        p[i]=p[i-1]+check(2,i,2);
    }
    
    while(q--){
        int x,y;
        cin>>x>>y;x--;
        if(y-x<=5){
            cout<<brute_force(string(a.begin()+x,a.begin()+y),
                            string(b.begin()+x,b.begin()+y))<<endl;
        }
        else{
            x++;
            cout<<check(0,x,2)+check(1,x+1,2)+p[y-2]-p[x+1]+check(2,y-1,1)+check(2,y,0)<<endl;
        }
    }
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}
