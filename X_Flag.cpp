// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e3+3;
///////////////////////////////////////////////////////////
int n,m,ans,arr[N][N];
char s[N][N];

inline void f(int column){
    vector<int> v,cnt;
    string s;
    for(int i=0;i<n;i++)s.push_back(::s[i][column]);
    for(int i=0;i<n;i++)cnt.push_back(arr[i][column]);

    //cerr<<s<<endl;
    //cerr<<"cnt:";for(auto i:cnt)cerr<<i<<",";cerr<<endl;

    v.push_back(0);
    for(int i=1;i<n;i++){
        if(s[i-1]!=s[i])v.push_back(i);
    }
    v.push_back(n);
    
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;

    for(int i=0;i+3<v.size();i++){
        int a=v[i],b=v[i+1],c=v[i+2],d=v[i+3];
        int sz=c-b;
        if(b-a>=sz && sz<=d-c){
            ans+=*min_element(cnt.begin()+b-sz,cnt.begin()+c+sz);
        }
    }
}

signed main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>s[i][j];

    for(int i=0;i<n;i++)arr[i][m-1]=1;
    for(int j=m-1;j--;){
        for(int i=0;i<n;i++){
            arr[i][j]=1+(s[i][j]==s[i][j+1])*arr[i][j+1];
        }
    }

    /*for(int i=0;i<n;i++){
        cerr<<"arr:";
        for(int j=0;j<m;j++)cerr<<arr[i][j]<<",";
        cerr<<endl;
    }*/

    for(int i=0;i<m;i++)f(i);

    cout<<ans<<endl;
}
