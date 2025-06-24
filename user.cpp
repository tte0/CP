// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
#ifdef ONLINE_JUDGE
    #define cerr if(0)cerr
#endif
using namespace std;
constexpr int N=3e5+5;
///////////////////////////////////////////////////////////
int n,q,cnt;
vector<int> adj[N],parent;
vector<pair<int,int>> edges,range;

struct segtree{
    int n;
    vector<int> st;
    segtree(int _n){
        n=_n;
        st.assign(2*n,0);
        for(int i=0;i<n;i++){
            update(i,1);
        }
    }
    void update(int x,int val){
        for(st[x+=n]+=val;x>1;x>>=1){
            st[x>>1]=st[x]+st[x^1];
        }
    }
    int query(int l,int r){//[l,r)
        int ans=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};

inline void dfs(int node=0,int p=-1){
    parent[node]=p;
    range[node].first=cnt++;
    for(auto i:adj[node]){
        if(i==parent[node])continue;
        dfs(i,node);
    }
    range[node].second=cnt;
}

inline int query(int x,segtree& st){
    auto [l,r]=range[edges[x].first];
    return abs(st.st[1]-2*st.query(l,r));
}

inline void update(int x,int y,segtree& st){
    st.update(x,y);
}

signed main(void){
    cin>>n;
    for(int i=1;i<n;i++){
        static int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back({x,y});
    }

    parent.resize(n);
    range.resize(n);
    dfs();
    for(auto& [x,y]:edges){
        if(parent[x]!=y)swap(x,y);
    }

    cerr<<"parent:";for(auto i:parent)cerr<<i+1<<",";cerr<<endl;
    cerr<<"range:";for(auto [a,b]:range)cerr<<"["<<a+1<<","<<b+1<<"] ";cerr<<endl;
    cerr<<"edges:";for(auto [a,b]:edges)cerr<<"["<<a+1<<","<<b+1<<"] ";cerr<<endl;

    segtree st(n);
    cin>>q;
    while(q--){
        static int x,y;
        cin>>x;
        if(x==1){
            cin>>x>>y;
            x--;
            update(x,y,st);
        }
        else{
            cin>>x;
            x--;
            cout<<query(x,st)<<endl;
        }
    }
}
