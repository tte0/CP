// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
constexpr int N=6e5+5;
///////////////////////////////////////////////////////////
int q/*,st[4*N],stl[4*N],str[4*N]*/;
vector<tuple<int,int,int>> querys;
vector<int> comp;



signed main(void){
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x;
        if(x==1){
            cin>>x>>y;
            comp.push_back(x);
            comp.push_back(y);
            querys.push_back({1,x,y});
        }
        else{
            cin>>x;
            comp.push_back(x);
            querys.push_back({2,x,-1});
        }
    }

    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());

    for(auto& [t,x,y]:querys){
        x=upper_bound(comp.begin(),comp.end(),x)-comp.begin();
        if(t==1)y=upper_bound(comp.begin(),comp.end(),y)-comp.begin();
    }

    vector<int> v[305];
    for(int i=0;i<q;i++){
        auto [t,x,y]=querys[i];
        if(t==1){
            for(int d=x;d<=y;d++)v[d].push_back(i);
        }
        else{
            cout<<v[x].size()<<endl;
            vector<bool> vis(305);
            for(auto i:v[x])vis[i]=true;
            for(int d=0;d<305;d++){
                int p=v[d].size();
                for(int i=p;i--;){
                    if(vis[v[d][i]]){
                        swap(v[d][i],v[d][--p]);
                    }
                }
                if(p!=v[d].size()){
                    v[d].resize(p);
                    v[d].push_back(i);
                }
                else{
                    v[d].resize(p);
                }
            }
        }
    }

}
