// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,q,x,arr[32];//00-same,01-reversed,10-zero,11-one
vector<int> v;

struct Node{
    int cnt=0;
    Node* child[2]={};
};
Node* root;

inline bool bit(int x,int b){
    return x&(1<<b);
}

inline void insert(int x){
    auto node=root;
    for(int b=32;b--;){
        node->cnt++;
        int i=bit(x,b);
        if(node->child[i]==nullptr){
            node->child[i]=new Node();
        }
        node=node->child[i];
    }
    node->cnt++;
}

inline void update(int x,int t){
    for(int b=32;b--;){
        if(t==1 && !bit(x,b))arr[b]=2;
        if(t==2 && bit(x,b))arr[b]=3;
        if(t==3)arr[b]^=bit(x,b);
    }
}

inline int querykth(int x){
    int ans=v[x-1];
    for(int b=32;b--;){
        if(arr[b]==1)ans^=1<<b;
        if(arr[b]==2)ans^=(bit(ans,b))<<b;
        if(arr[b]==3)ans^=(bit(ans,b)^1)<<b;
    }
    return ans;
}

inline int querykthsmallest(int x){

}

inline void solve(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    root=new Node();
    for(auto i:v)insert(i);

    cin>>q;
    while(q--){
        cin>>x;
        if(x==1){
            cin>>x;
            update(x,1);
        }
        else if(x==2){
            cin>>x;
            update(x,2);
        }
        else if(x==3){
            cin>>x;
            update(x,3);
        }
        else if(x==4){
            cin>>x;
            cout<<querykth(x)<<endl;
        }
        else{
            cin>>x;
            cout<<querykthsmallest(x)<<endl;
        }

    }
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();    
}
