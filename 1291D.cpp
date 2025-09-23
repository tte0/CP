// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,q,pref[N][26];
string s;

signed main(void){
    cin>>s>>q;
    n=s.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            pref[i+1][j]=pref[i][j]+(s[i]==j+'a');
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            //cerr<<"skipped :p"<<endl;
            cout<<"Yes"<<endl;
            continue;
        }
        vector<int> v;
        char c;
        for(int j=0;j<26;j++){
            int cnt=pref[y][j]-pref[x-1][j];
            if(cnt){
                v.push_back(cnt);
                c=j;
            }
        }
        //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;
        if(v.size()==1){
            cout<<"No"<<endl;
            continue;
        }
        if(v.size()>2){
            cout<<"Yes"<<endl;
            continue;
        }
        if(s[x-1]!=s[y-1]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
