// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast16_t
using namespace std;
constexpr int N=1e4;
struct cost{
    uint32_t msb=20000,b=1<<24;
    cost(){}
    cost(uint32_t __msb){
        msb=__msb;
    }
    cost(uint32_t __msb, uint32_t __b){
        msb=__msb;
        b=__b;
    }
    bool operator<(const cost& other)const{
        return msb!=other.msb?msb<other.msb:b<other.b;
    }
    bool operator>(const cost& other)const{return other<*this;}
    bool operator<=(const cost& other)const{return !(*this>other);}
    bool operator>=(const cost& other)const{return !(*this<other);}
    cost operator+(const cost& other){
        cost ans;
        ans.msb=max(msb,other.msb);
        if(msb>other.msb){
            ans.b=b+(other.b>>(msb-other.msb));
        }
        else{
            ans.b=other.b+(b>>(other.msb-msb));
        }
        if(ans.b&(1<<25)){
            ans.msb++;
            ans.b>>=1;
        }
        return ans;
    }
};
///////////////////////////////////////////////////////////
int n,m,k;
cost arr[N][N];
vector<tuple<int,int>> v;

signed main(void){
    cin>>n>>m>>k;
    v.resize(k);
    for(auto& [a,b]:v)cin>>a>>b;

    for(int i=0;i<k-1;i++){
        auto [xa,ya]=v[i];
        xa--,ya--;
        for(int j=i+1;j<k;j++){
            auto [xb,yb]=v[j];
            xb--,yb--;
            arr[i][j]=arr[j][i]=cost(max(abs(xa-xb),abs(ya-yb)));
        }
    }

    vector<bool> vis(k,false);
    vector<int> bt(k);bt[0]=-1;

    priority_queue<tuple<cost,int,int>,vector<tuple<cost,int,int>>,greater<tuple<cost,int,int>>> q;
    q.push({cost(0,0),0,-1});
    while(q.size()){
        auto [c,node,_bt]=q.top();q.pop();
        if(vis[node])continue;
        vis[node]=1;
        bt[node]=_bt;
        if(node==k-1){
            vector<int> t;
            while(node!=-1){
                t.push_back(node);
                node=bt[node];
            }
            reverse(t.begin(),t.end());

            cout<<t.size()<<endl;
            for(auto i:t)cout<<1+i<<" ";
            return 0;
        }
        for(int i=0;i<k;i++){
            if(i==node)continue;
            q.push({c+arr[node][i],i,node});
        }
    }
    abort();
}
