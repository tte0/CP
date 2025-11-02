// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=1e9+7;
constexpr inline int fp(int b,int p){
    int ans=1;
    while(p){
        if(p&1)ans=(ans*b)%MOD;
        p>>=1;
        b=(b*b)%MOD;
    }
    return ans;
}
constexpr array<int,105> compute_fact(){
    array<int,105> fact;
    fact[0]=1;
    for(int i=1;i<105;i++)fact[i]=(fact[i-1]*i)%MOD;
    return fact;
}
///////////////////////////////////////////////////////////
int n,x;
vector<int> v;
constexpr array<int,105> fact=compute_fact();

inline vector<int> middle(const vector<int>& l,const vector<int>& r){
    /*cerr<<"middle-"<<endl;
    cerr<<" l: ";for(const auto& i:l)cerr<<i<<",";cerr<<endl;
    cerr<<" r: ";for(const auto& i:r)cerr<<i<<",";cerr<<endl;*/

    vector<int> m(n);
    vector<bool> included(n,false);
    for(int i=0;i<n;i++){
        //cerr<<"i: "<<i<<" (main loop)"<<endl;
        if(l[i]>r[i]){
            // something has gone terribly wrong
            // lets fuck the runtime even more
            int x=1/(1-1);
            cout<<x<<endl;
        }
        else if(l[i]<r[i]){
            int pl=l[i],pr=r[i];
            while(pl<pr){
                while(included[--pr]);
                if(!(pl<pr))break;
                while(included[++pl]);
            }
            m[i]=pl;
            //cerr<<"m[i]="<<m[i]<<endl;
            included[m[i++]]=true;
            for(int p=n;i<n;){
                //cerr<<"p: "<<p<<" (start of loop)"<<endl;
                while(included[--p]);
                //cerr<<"p: "<<p<<" (after while)"<<endl;
                m[i++]=p;
            }
            break;
        }
        else{
            m[i]=l[i];
            included[m[i]]=true;
        }
    }
    return m;
}

inline bool check(const vector<int>& p){
    int cost=0;
    for(int i=0;i<n;i++){
        cost+=max(v[p[i]]-i,int(0));
    }
    return cost<=x;
}

signed main(void){
    cin>>n>>x;
    v.resize(n);
    for(auto& i:v)cin>>i;
    sort(v.begin(),v.end());



    vector<int> l(n),r(n),m;
    iota(l.begin(),l.end(),0);
    iota(r.rbegin(),r.rend(),0);
    while(l!=r){
        m=middle(l,r);

        cerr<<"l: ";for(const auto& i:l)cerr<<i<<",";cerr<<endl;
        cerr<<"m: ";for(const auto& i:m)cerr<<i<<",";cerr<<endl;
        cerr<<"r: ";for(const auto& i:r)cerr<<i<<",";cerr<<endl;
        cerr<<endl;

        if(check(m)){
            next_permutation(m.begin(),m.end());
            l=m;
        }
        else{
            r=m;
        }
    }

    cerr<<"l: ";for(const auto& i:l)cerr<<i<<",";cerr<<endl;
    int ans=0;
    vector<int> included(n,false);
    for(int i=0;i<n;i++){
        for(int p=l[i];p--;){
            ans+=fact[n-i-1]*!(included[p]);
            ans%=MOD;
        }
        included[l[i]]=true;
    }

    cout<<ans<<endl;
}
