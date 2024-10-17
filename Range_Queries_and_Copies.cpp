// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=200005;
///////////////////////////////////////////////////////////
int n,q,x,y,k,cnt;
vector<int> v;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x=0):val(x),left(NULL),right(NULL){}
    Node(Node* x):val(x->val),left(x->left),right(x->right){}
    Node(Node* l,Node* r){
        left=l,right=r,val=0;
        if(l)val+=l->val;
        if(r)val+=r->val;
    }
};

#define mid (l+r>>1)

inline Node* build(int l=1,int r=n){
    if(l==r)return new Node(v[l-1]);
    return new Node(build(l,mid),build(mid+1,r));
}

inline Node* update(Node* node,int l=1,int r=n){
    if(l==r)  return new Node(y);
    if(x<=mid)return new Node(update(node->left,l,mid),node->right);
    else      return new Node(node->left,update(node->right,mid+1,r));
}

inline int query(Node* node,int l=1,int r=n){
    if(r<x || y<l)return 0;
    if(x<=l && r<=y)return node->val;
    return query(node->left,l,mid)+query(node->right,mid+1,r);
}

signed main(void){
    cin>>n>>q;
    v.resize(n);
    for(int& i:v)cin>>i;

    Node* root[q+5];   
    root[++cnt]=build();

    while(q--){
        cin>>x;
        if(x==1){
            cin>>k>>x>>y;
            root[k]=update(new Node(root[k]));
        }
        else if(x==2){
            cin>>k>>x>>y;
            cout<<query(root[k])<<endl;
        }
        else{
            cin>>k;
            root[++cnt]=new Node(root[k]);
        }
    } 
}
