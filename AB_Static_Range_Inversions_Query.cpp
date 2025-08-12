// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1e5+5;
constexpr int BLOCK=316;
///////////////////////////////////////////////////////////
int n,q,st[2*N],ans[N];
vector<int> v,comp;
vector<pair<int,pair<int,int>>> querys;

inline int query(int l,int r){
    int ans=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)ans+=st[l++];
        if(r&1)ans+=st[--r];
    }
    return ans;
}

inline void update(int x,int val){
    for(st[x+=n]+=val;x>1;x>>=1){
        st[x>>1]=st[x]+st[x^1];
    }
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>q;
    v.resize(n);
    querys.resize(q);
    for(int& i:v)cin>>i;
    for(int i=0;i<q;i++){
        cin>>querys[i].second.first>>querys[i].second.second;
        querys[i].first=i;
    }

    comp=v;
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    for(int i=0;i<n;i++)v[i]=lower_bound(comp.begin(),comp.end(),v[i])-comp.begin();

    sort(querys.begin(),querys.end(),[&](const auto& a,const auto& b){
        return  a.second.first/BLOCK==b.second.first/BLOCK?
                a.second.second<b.second.second:
                a.second.first<b.second.first;
    });

    int l=0,r=0,sum=0;
    for(const auto& _:querys){
        int i=_.first,ql=_.second.first,qr=_.second.second;
        while(ql<l){
            l--;
            sum+=query(0,v[l]);
            update(v[l],1);
        }
        while(r<qr){
            sum+=query(v[r]+1,n);
            update(v[r],1);
            r++;
        }
        while(l<ql){
            update(v[l],-1);
            sum-=query(0,v[l]);
            l++;
        }
        while(qr<r){
            r--;
            update(v[r],-1);
            sum-=query(v[r]+1,n);
        }

        ans[i]=sum;
    }

    for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
}
