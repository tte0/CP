// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#pragma GCC target("avx2,bmi,bmi2,popcnt")
#define int int_fast64_t
using namespace std;
constexpr int N=3e5+5;
///////////////////////////////////////////////////////////
int n,rmqmin[N][19],rmqmax[N][19];
vector<int> v;

inline int querymin(int l,int r){//[l,r] index
    int d=__lg(r-l);
    return v[rmqmin[l][d]] <= v[rmqmin[r-(1<<d)+1][d]] ? rmqmin[l][d] : rmqmin[r-(1<<d)+1][d];
}

inline int querymax(int l,int r){//[l,r] index
    int d=__lg(r-l);
    return v[rmqmax[l][d]] > v[rmqmax[r-(1<<d)+1][d]] ? rmqmax[l][d] : rmqmax[r-(1<<d)+1][d];
}

int f(int l,int r){//[l,r]
    if(l>r)return 0;
    if(l==r)return 1;

    int argmin=querymin(l,r),argmax=querymax(l,r);
    /*cerr<<" --- l,r:"<<l<<","<<r<<" ---"<<endl;
    cerr<<"argmin="<<argmin<<" , argmax="<<argmax<<endl;*/
    if(v[argmin]==v[l] && v[argmax]==v[r])return 1;
    if(v[argmin]!=v[l])return f(l,argmin-1)+f(argmin,r);
    if(v[argmax]!=v[r])return f(l,argmax)+f(argmax+1,r);
    assert(false);
    return -10000000;
}

signed main(void){
    cin>>n;
    v.resize(n);    
    for(auto& i:v)cin>>i;

    /*auto comp=v;
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    for(auto& i:v)i=lower_bound(comp.begin(),comp.end(),i)-comp.begin();*/

    for(int i=0;i<n;i++){
        rmqmin[i][0]=rmqmax[i][0]=i;
    }
    for(int j=0;j<18;j++){
        for(int i=0;i+(1<<j)<n;i++){
            rmqmin[i][j+1] = v[rmqmin[i][j]] <= v[rmqmin[i+(1<<j)][j]] ? rmqmin[i][j] : rmqmin[i+(1<<j)][j];
            rmqmax[i][j+1] = v[rmqmax[i][j]] > v[rmqmax[i+(1<<j)][j]] ? rmqmax[i][j] : rmqmax[i+(1<<j)][j];
        }
        for(int i=max(int(0),n-(1<<j));i<n;i++){
            rmqmin[i][j+1] = rmqmin[i][j];
            rmqmax[i][j+1] = rmqmax[i][j];
        }
    }

    /*for(int j=0;j<3;j++){
        cerr<<"rmqmin: ";
        for(int i=0;i<n;i++){
            cerr<<rmqmin[i][j]<<",";
        }
        cerr<<endl;
    }cerr<<endl;
    for(int j=0;j<3;j++){
        cerr<<"rmqmax: ";
        for(int i=0;i<n;i++){
            cerr<<rmqmax[i][j]<<",";
        }
        cerr<<endl;
    }cerr<<endl;*/

    cout<<f(0,n-1)<<endl;
}
