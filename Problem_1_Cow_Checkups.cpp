// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=5e5+5;
///////////////////////////////////////////////////////////
int n;
vector<int> a,b,arr[N],brr[N];

inline int f(const vector<int>& a,const vector<int>& b){
    int ans=0,sum=0;
    bool half_way_done=false;
    int cntl=0,cntr=0;
    for(int x:a){
        if(x<n/2){
            while(cntl<b.size() && b[cntl]<=x)cntl++;
            while(cntr<b.size() && n-x-1<=/*can be <*/b[b.size()-cntr-1]){
                sum+=n-b[b.size()-cntr-1];
                cntr++;
            }
            int cntm=b.size()-cntl-cntr;
            ans+=sum+(x+1)*cntm;
        }
        else{
            if(!half_way_done){
                cntr=sum=0;
                while(cntr<b.size() && x<b[b.size()-cntr-1]){
                    sum+=n-b[b.size()-cntr-1];
                    cntr++;
                }
                half_way_done=true;
            }
            while(0<cntr && b[b.size()-cntr]<=x){
                sum-=n-b[b.size()-cntr];
                cntr--;
            }
            ans+=sum;
        }
    }
    return ans;
}

inline int ssum(int x){return (x*(x+1))>>1;}

inline int equals(const vector<int>& a,const vector<int>& b){
    int pa=0,pb=0,ans=0;
    while(pa<a.size() && pb<b.size()){
        if(a[pa]<b[pb])pa++;
        else if(a[pa]>b[pb])pb++;
        else{
            ans+=ssum(a[pa]);
            ans+=min(a[pa]+1,n-a[pa]);
            ans+=ssum(n-a[pa]-1);
            pa++;
            pb++;
        }
    }
    return ans;
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    a.resize(n);
    b.resize(n);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;

    for(int i=0;i<n;i++){
        a[i]--;b[i]--;
        arr[a[i]].push_back(i);
        brr[b[i]].push_back(i);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        int t=equals(arr[i],brr[i]);
        ans+=t;
        t=f(arr[i],brr[i]);
        ans+=t;
        for(auto& x:arr[i])x=n-x-1;
        for(auto& x:brr[i])x=n-x-1;
        reverse(arr[i].begin(),arr[i].end());
        reverse(brr[i].begin(),brr[i].end());
        t=f(arr[i],brr[i]);
        ans+=t;
    }

    cout<<ans<<endl;
}
