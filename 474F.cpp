/*
Author: Teoman Ata Korkmaz
*/
#pragma GCC optimize("O3,fast-math,unroll-loops")
#include <bits/stdc++.h> 
#define int i32
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define e2(x) (1LL<<(x))
#define lg(x) (__lg(x))
#define gcd(x,y) __gcd(x,y)
#define isint(x) (ceil((x))==floor((x)))
#define mset(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define compress(x) sort(all(x));x.resize(unique(all(x))-x.begin())
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);cout<<fixed<<setprecision(0);cerr<<fixed<<setprecision(0)
using namespace std;
typedef int_fast32_t i32;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
const int N=1e5+5;
const int BLOCK=300;
int n,m,k,t,q,a,b,x,y,ans[N],st[N][17],id[N];
int v[N];

inline bool cmp(const iii& a,const iii& b){
    if(a.ss.ff/BLOCK!=b.ss.ff/BLOCK)return a.ss.ff<b.ss.ff;
    return a.ss.ss<b.ss.ss;
}

inline int query(int l,int r){
    if(l==r)return st[l][0];
    int j=lg(r-l+1);
    return gcd(st[l][j],st[r-e2(j)+1][j]);
}

inline void solve(void){
    cin>>n;
    vi comp(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        comp[i]=v[i];
    }
    compress(comp);
    for(int i=0;i<n;i++)id[i]=lower_bound(all(comp),v[i])-comp.begin();
    for(int i=0;i<n;i++)st[i][0]=v[i];
    for(int j=1;j<17;j++){
        for(int i=0;i<n;i++){
            st[i][j]=st[i][j-1];
            if(i+e2(j-1)<n)st[i][j]=gcd(st[i][j],st[i+e2(j-1)][j-1]);
        }
    }
    

    cin>>q;
    viii querys;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        querys.pb({i,{x-1,y-1}});
    }
    sort(all(querys),cmp);

    int l=0,r=0;
    vi cnt(comp.size(),0);cnt[id[0]]++;
    for(auto& _:querys){
        int ind=_.ff,x=_.ss.ff,y=_.ss.ss;
        //debug("query:",ind,x,y);
        while(x<l)cnt[id[--l]]++;
        while(r<y)cnt[id[++r]]++;
        while(l<x)cnt[id[l++]]--;
        while(y<r)cnt[id[r--]]--;
        int t=query(l,r);
        auto it=lower_bound(all(comp),t);
        if(it==comp.end() || *it!=t)ans[ind]=(r-l+1);
        else ans[ind]=(r-l+1)-cnt[it-comp.begin()];
        //debug("cnt:",cnt);
    }

    for(int i=0;i<q;i++)cout<<(ans[i])<<endl;
}

signed main(void){
    fastio;
    solve();
}
