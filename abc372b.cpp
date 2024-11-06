#include <bits/stdc++.h>
using namespace std;
int n;

inline int f(int n){
    int ans=-1;
    while(n){
        ans++;
        n/=3;
    }
    return ans;
}

inline int g(int n){
    return n?3*g(n-1):1;
}

int main(){
    cin>>n;
    vector<int> v;
    while(n){
        v.push_back(f(n));
        n-=g(f(n));
    }

    cout<<v.size()<<endl;
    for(auto i:v)cout<<i<<" ";
}
