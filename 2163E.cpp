// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e3+3;
///////////////////////////////////////////////////////////
int n,m,c;
string s[N];

inline void answer(int r,int c){
    cout<<r+1<<" "<<c+1<<endl;
}

inline void findConnected(){
    for(int i=0;i<n;i++){
        int j=0,cnt=0;
        while(j<n && s[i][j]=='0')j++;
        while(j<n && s[i][j]=='1')j++,cnt++;
        while(j<n && s[i][j]=='0')j++;
        if(j==n && cnt>1){
            answer(i,0);
            return;
        }
    }
    for(int j=0;j<n;j++){
        int i=0,cnt=0;
        while(i<n && s[i][j]=='0')i++;
        while(i<n && s[i][j]=='1')i++,cnt++;
        while(i<n && s[i][j]=='0')i++;
        if(i==n && cnt>1){
            answer(0,j);
            return;
        }
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=s[i][j]=='1';
        }
        if(cnt==0){
            answer(i,0);
            return;
        }
    }
    assert(false);
}

inline void findDisonnected(){
    for(int i=0;i<n;i++){
        int j=0;
        while(j<n && s[i][j]=='0')j++;
        while(j<n && s[i][j]=='1')j++;
        while(j<n && s[i][j]=='0')j++;
        if(j<n){
            answer(i,j);
            return;
        }
    }
    for(int j=0;j<n;j++){
        int i=0;
        while(i<n && s[i][j]=='0')i++;
        while(i<n && s[i][j]=='1')i++;
        while(i<n && s[i][j]=='0')i++;
        if(i<n){
            answer(i,j);
            return;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='1'){
                answer(i,j);
                return;
            }
        }
    }
    assert(false);
}

inline void first(){
    cin>>n>>c;
    for(int i=0;i<n;i++)cin>>s[i];
    
    if(c){
        assert(c);
        findConnected();
    }
    else {
        assert(!c);
        findDisonnected();
    }
}

inline void answer(bool b){
    cout<<(b?1:0)<<endl;
}

inline void second(){
    cin>>n;
    string a,b;
    cin>>a>>b;
    int p=0;
    while(p<n && a[p]=='0')p++;
    while(p<n && a[p]=='1')p++;
    while(p<n && a[p]=='0')p++;
    if(p<n){
        answer(false);
        return;
    }
    p=0;
    while(p<n && b[p]=='0')p++;
    while(p<n && b[p]=='1')p++;
    while(p<n && b[p]=='0')p++;
    if(p<n){
        answer(false);
        return;
    }

    for(int i=0;i<n-1;i++){
        if(a[i]=='1' && a[i+1]=='1'){
            answer(true);
            return;
        }
    }
    for(int i=0;i<n-1;i++){
        if(b[i]=='1' && b[i+1]=='1'){
            answer(true);
            return;
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)cnt+=a[i]=='1';
    if(cnt==0){
        answer(true);
        return;
    }
    cnt=0;

    for(int i=0;i<n;i++)cnt+=b[i]=='1';
    if(cnt==0){
        answer(true);
        return;
    }
    answer(false);
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t;
    cin>>s>>t;
    while(t--){
        if(s=="first")first();
        else second();
    }
}
/*
10...01 -> disconnected
.X11X. -> connected
0..0 -> connected

*/