// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#pragma GCC target("avx2,bmi,bmi2,popcnt")
using namespace std;
uint64_t mt() {
    static uint64_t x = 88172645463125252ULL; // seed (non-zero)
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    return x * 2685821657736338717ULL;
}
struct treap{
    int n;
    size_t root;
    vector<char> key;
    vector<uint32_t> weight;
    vector<size_t> left,right;
    vector<uint> size;
    vector<bool> lazy;

    size_t newNode(char c,size_t l,size_t r){
        key.push_back(c);
        weight.push_back(mt());
        left.push_back(l);
        right.push_back(r);
        size.push_back(1);
        return key.size()-1;
    }

    treap(const string& s,int query_hint=0){
        n=s.size();
        key.reserve(n+query_hint);
        weight.reserve(n+query_hint);
        left.reserve(n+query_hint);
        right.reserve(n+query_hint);
        size.reserve(n+query_hint);
        lazy.reserve(n+query_hint);

        //create root node
        root=newNode(s[0],-1,-1);
        for(int i=1;i<n;i++){
            root=merge(root,newNode(s[i],-1,-1));
        } 
    }

    //safe
    inline uint safe_size(size_t node){
        return node==-1?0:size[node];
    }

    inline void compute_size(size_t node){
        size[node]=safe_size(left[node])+safe_size(right[node])+1;
    }

    inline void push(size_t node){
        assert(node!=-1);
        if(lazy[node]){
            swap(left[node],right[node]);
            if(left[node]!=-1)lazy[left[node]]=!lazy[left[node]];
            if(right[node]!=-1)lazy[right[node]]=!lazy[right[node]];
            lazy[node]=0;
        }
    }

    //return the root of mergged product
    size_t merge(size_t l,size_t r){
        if(l==-1)return r;
        if(r==-1)return l;
        if(weight[l]>weight[r]){
            push(l);
            right[l]=merge(right[l],r);
            compute_size(l);
            return l;
        }
        else{
            push(r);
            left[r]=merge(l,left[r]);
            compute_size(r);
            return r;
        }
    }

    //modify the l,r product
    //0-indexed 
    //[0,index) [index,size)
    void split(size_t node,size_t& l,size_t& r,uint index){
        if(node==-1){
            l=r=-1;
            return;
        }
        // size of left child gives 0-index of me
        push(node);
        if(safe_size(left[node])>=index){
            split(left[node],l,left[node],index);
            r=node;
            compute_size(r);
        }
        else{
            split(right[node],right[node],r,index-(safe_size(left[node])+1/*da root itself*/));
            l=node;
            compute_size(l);
        }
    } 

    //0-indexed [l,r)
    void reverse(int ql,int qr){
        size_t l,m,r;
        split(root,l,r,qr);
        split(l,l,m,ql);
        lazy[m]=!lazy[m];
        root=merge(merge(l,m),r);
    }

    string str(){return str(root);}
    string str(size_t node){
        stringstream ss;
        auto recurse=[&](size_t node,auto&& recurse){
            if(node==-1)return;
            push(node);
            recurse(left[node],recurse);
            ss<<key[node];
            recurse(right[node],recurse);
        };
        recurse(node,recurse);
        return ss.str();
    }
};
///////////////////////////////////////////////////////////
int n,q;
string s;

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q>>s;

    treap trp(s);

    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        trp.reverse(x,y);
    }

    cout<<trp.str()<<endl;
}
