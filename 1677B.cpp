// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,m;
string s;

inline void solve(){
    cin>>n>>m>>s;
    vector<int> row(n*m),col(n*m),what(m,1); 

    int r_cnt=0,c_cnt=0;
    for(int i=0;i<n*m;i++){
        r_cnt+=(s[i]=='1');
        if(i>=m)r_cnt-=(s[i-m]=='1');
        row[i]=bool(r_cnt);
        if(i>=m)row[i]+=row[i-m];

        if(s[i]=='1'){
            c_cnt+=what[i%m];
            what[i%m]=0;
        }
        col[i]=c_cnt;
    }

    for(int i=0;i<n*m;i++)cout<<row[i]+col[i]<<" ";
    cout<<endl;

    /*for(int i=0;i<n;i++){
        cerr<<"row: ";
        for(int j=0;j<m;j++)cerr<<row[i*m+j]<<",";
        cerr<<endl;
    }cerr<<endl;

    for(int i=0;i<n;i++){
        cerr<<"col: ";
        for(int j=0;j<m;j++)cerr<<col[i*m+j]<<",";
        cerr<<endl;
    }cerr<<endl;*/
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}
