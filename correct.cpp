// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,q,x,y,w;
vector<int> v;

struct Node{
    int min=2e9;
    int min2=2e9;
    int sum=0;
    int cnt=1;
    int lazy=0;
};

struct segtree{
    void update(int x,int y,int val){
        x--,y--;
        for(int i=x;i<=y;i++)v[i]=max(v[i],val);
    }
    int query(int x,int y){
        int ans=0;
        x--,y--;
        for(int i=x;i<=y;i++)ans+=v[i];
        return ans;
    }
};

signed main(void){
    cin>>n>>q;
    v.resize(n);
    for(auto& i:v)cin>>i;

    segtree st;
    while(q--){
        cin>>x;
        if(x==1){//update
            cin>>x>>y>>w;
            st.update(x,y,w);
        }
        else{//query
            cin>>x>>y;
            cout<<st.query(x,y)<<endl;
        }
    }
}
