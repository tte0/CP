// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m,fa[N],ans[N];
string s;
vector<int> adj[N];

int dsu(int x){
    if(fa[x]<=0)return x;
    return fa[x]=dsu(fa[x]);
}

void merge(int a,int b){
    a=dsu(a);
    b=dsu(b);
    if(a==b)return;
    fa[a]+=fa[b];
    fa[b]=a;


}

inline int ssum(int x){
    return (x*(x-1))>>1;
}

signed main(void){
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        adj[x].push_back(y);
    }    

    for(int node=1;node<=n;node++){
        if(s[node-1]=='1'){
            for(const auto& i:adj[node]){
                merge(node,i);
            }
        }
    }

    //cerr<<"fa: ";for(int i=0;i<=n;i++)cerr<<fa[i]<<" ";cerr<<endl<<endl;

    int cnt=0;
    for(int node=n;node;node--){
        if(s[node-1]=='0'){
            cnt-=ssum(-fa[dsu(node)]);
            for(const auto& i:adj[node]){
                if(dsu(node)!=dsu(i))cnt-=ssum(-fa[dsu(i)]);
                merge(node,i);
            }
            cnt+=ssum(-fa[dsu(node)]);
        }
        //cerr<<"fa: ";for(int i=0;i<=n;i++)cerr<<fa[i]<<" ";cerr<<endl;
        cnt+=-fa[dsu(node)];
        ans[node]=cnt;
        fa[dsu(node)]--;
        //cerr<<"fa: ";for(int i=0;i<=n;i++)cerr<<fa[i]<<" ";cerr<<endl<<endl;
    }

    for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
}
