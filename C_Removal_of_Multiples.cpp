// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1<<22;
///////////////////////////////////////////////////////////
int q;

struct segtree{
    int n;
    vector<int> st;
    segtree(int _n){
        n=_n;
        st.resize(2*n);
        for(int i=0;i<n;i++)update(i,1);
    }
    void update(int x,int val){
        for(st[x+=n]=val;x>1;x>>=1){
            st[x>>1]=st[x]+st[x^1];
        }
    }
    int query(int b){
        int x;
        for(x=1;x<n;){
            if(st[x<<1]<b){
                b-=st[x<<1];
                x=(x<<1)+1;
            }
            else{
                x<<=1;
            }
        }
        return x-n+1;
    }
};

signed main(void){
    segtree st(N);
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x<N && st.st[x+N-1]){
            for(int i=x;i<N;i+=x){
                st.update(i-1,0);
            }
        }
        cout<<st.query(y)<<endl;
    }

    //for(int i=0;i<20;i++)cerr<<st.st[i+N];
}
