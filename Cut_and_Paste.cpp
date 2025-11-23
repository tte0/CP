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
    uint_fast32_t root;
    vector<char> key;
    vector<uint32_t> weight;
    vector<uint_fast32_t> left,right;
    vector<uint> size;

    uint_fast32_t newNode(char c,uint_fast32_t l,uint_fast32_t r){
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

        //create root node
        root=newNode(s[0],-1,-1);
        for(int i=1;i<n;i++){
            root=merge(root,newNode(s[i],-1,-1));
        } 
    }

    //safe
    inline uint safe_size(uint_fast32_t node){
        return node==-1?0:size[node];
    }

    inline void compute_size(uint_fast32_t node){
        size[node]=safe_size(left[node])+safe_size(right[node])+1;
    }

    //return the root of mergged product
    uint_fast32_t merge(uint_fast32_t l,uint_fast32_t r){
        if(l==-1)return r;
        if(r==-1)return l;
        if(weight[l]>weight[r]){
            right[l]=merge(right[l],r);
            compute_size(l);
            return l;
        }
        else{
            left[r]=merge(l,left[r]);
            compute_size(r);
            return r;
        }
    }

    //modify the l,r product
    //0-indexed 
    //[0,index) [index,size)
    void split(uint_fast32_t node,uint_fast32_t& l,uint_fast32_t& r,uint index){
        if(node==-1){
            l=r=-1;
            return;
        }
        // size of left child gives 0-index of me
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
    void cut(int ql,int qr){
        uint_fast32_t l,m,r;
        split(root,l,r,qr);
        split(l,l,m,ql);
        root=merge(l,merge(r,m));
    }

    string str(){return str(root);}
    string str(uint_fast32_t node){
        stringstream ss;
        recurse(node,ss);
        return ss.str();
    }
    void recurse(uint_fast32_t node,stringstream& ss){
            if(node==-1)return;
            recurse(left[node],ss);
            ss<<key[node];
            recurse(right[node],ss);
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
        trp.cut(x,y);
    }

    cout<<trp.str()<<endl;
}
