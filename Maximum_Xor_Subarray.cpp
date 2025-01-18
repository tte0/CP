// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

struct Node{
    Node* zero=nullptr;
    Node* one=nullptr;
};

Node* root=new Node();

inline void insert(int x){
    Node* node=root;
    for(int b=31;b>=0;b--){
        if((x&(1<<b))==0){
            if(node->zero==nullptr)node->zero=new Node();
            node=node->zero;
        }
        else{
            if(node->one==nullptr)node->one=new Node();
            node=node->one;
        }
    }
}

inline int dfs(Node* x,Node* y,int b=31,int dx=0,int dy=0){
    if(b<0)return 0;
    assert(x!=nullptr);
    assert(y!=nullptr);
    //cerr<<"dfs:"<<dx<<","<<dy<<"-"<<b<<endl;
    int ans=0;
    if(x->zero!=nullptr && y->one!=nullptr){//0-1
        ans=max(ans,dfs(x->zero,y->one,b-1,dx,dy+(1<<b))+(1<<b));
    }
    if(x->one!=nullptr && y->zero!=nullptr){//1-0
        ans=max(ans,dfs(x->one,y->zero,b-1,dx+(1<<b),dy)+(1<<b));
    }
    if(ans)return ans;
    if(x->zero!=nullptr && y->zero!=nullptr){//0-0
        ans=max(ans,dfs(x->zero,y->zero,b-1,dx,dy));
    }
    if(x->one!=nullptr && y->one!=nullptr){//1-1
        ans=max(ans,dfs(x->one,y->one,b-1,dx+(1<<b),dy+(1<<b)));
    }
    return ans;
}

signed main(void){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    for(int i=1;i<n;i++)v[i]^=v[i-1];
    v.insert(v.begin(),0);
    n++;
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;

    for(auto i:v){
        insert(i);
    }

    cout<<dfs(root,root);
}
