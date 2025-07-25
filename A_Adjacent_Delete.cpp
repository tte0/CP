// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;

signed main(void){
    cin>>n;
    vector<int> va,vb;
    deque<int> a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i%2==0)va.push_back(x);
        else vb.push_back(x);
    } 
    
    sort(va.begin(),va.end());
    sort(vb.rbegin(),vb.rend());
    for(auto i:va)a.push_back(i);
    for(auto i:vb)b.push_back(i);

    int ans=0;
    while(b.size()){
        if(abs(a.front()-b.front())>abs(a.back()-b.back())){
            ans+=abs(a.front()-b.front());
            a.pop_front();
            b.pop_front();
        }
        else{
            ans+=abs(a.back()-b.back());
            a.pop_back();
            b.pop_back();
        }
    }

    cout<<ans<<endl;
}
