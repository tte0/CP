// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int INF=1e9;
constexpr int N=4e5+5;
///////////////////////////////////////////////////////////
int n,q;
vector<int> v;
vector<tuple<int,int>> wtf[N];

inline void something(int i,int d,int val,vector<tuple<int,int>>& arr){
    arr.push_back({i,val});
    wtf[i].push_back({i+d,val});
}

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;
    
    vector<tuple<int,int>> arr;
    for(int i=0;i<n;i++){
        something(i,0,INF,arr);
    }
    for(int d=1;d<n-1;d++){
        if(arr.empty())break;
        vector<tuple<int,int>> new_arr;
        for(int i=0;i<int(arr.size())-1;i++){
            auto [i1,val1]=arr[i];
            auto [i2,val2]=arr[i+1];
            if(i1+1!=i2)continue;
            if(min(val1,val2)>abs(v[i1]-v[i1+d])){
                something(i,d,abs(v[i1]-v[i1+d]),new_arr);
            }
        }
        swap(arr,new_arr);
    }

    for(int i=0;i<n;i++){
        cerr<<"wtf["<<i<<"]: ";
        for(auto [a,b]:wtf[i])cerr<<"{"<<a<<","<<(b==INF?-1:b)<<"} ";
        cerr<<endl;
    }

    
}
