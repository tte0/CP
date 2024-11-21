// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n=10,m=9;
vector<vector<double>> dat={
    {197, 393, 16, 819, 1600, 4, 512, 200, 275},
    {918, 1836, 32, 1640, 3584, 4, 1536, 800, 425},
    {312, 624, 80, 1935, 600, 6, 256, 64, 300},
    {623.8, 623.8, 40, 1536, 400, 6, 256, 512, 240},
    {1671, 3341, 94, 3993.6, 600, 6, 256, 128, 700},
    {1671, 3341, 141, 4915.2, 900, 6, 256, 128, 600},
    {1800, 3500, 192, 8192, 1800, 8, 256, 128, 700},
    {2250, 4500, 192, 8192, 1800, 8, 512, 256, 1000},
    {1, 1, 1, 2, 2, 2, 3, 3, 2},
    {1, 1, 1, 2, 2, 2, 3, 3, 500},
};

signed main(void){
    cerr<<fixed<<setprecision(4)<<endl;
    cout<<fixed<<setprecision(3)<<endl;
    for(int i=0;i<n;i++)dat[i].back()=1/dat[i].back();
    for(int j=0;j<m;j++){
        double mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,dat[i][j]);
        }
        for(int i=0;i<n;i++){
            dat[i][j]/=mx;
        }
    }

    for(auto _:dat){
        for(auto i:_)cerr<<i<<", ";
        cerr<<endl;
    }

    vector<double> weights={
        .13, .13, .04, .04, .06, .02, .06, .02, .50
    };
    
    vector<double> score(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            score[i]+=weights[j]*dat[i][j];
        }
    }

    vector<string> names={
        "v5e ","v6e ","A100","A800","H100","H200","B100","B200","Den1","Den2"
    };
    vector<tuple<double,string>> v;
    for(int i=0;i<n;i++)v.push_back({score[i],names[i]});
    sort(v.rbegin(),v.rend());
    for(auto [b,a]:v)if(a[0]!='D')cout<<a<<": "<<b<<endl;
}

