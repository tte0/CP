// Author: Teoman Ata Korkmaz
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
mt19937 mt(clock()*(clock()%2?(clock()-1):(clock()+1)));
constexpr int MOD=1e18+9;
///////////////////////////////////////////////////////////
int n,m,ans,b=mt()%MOD;
string s;
vector<int> v;
map<int,int> mp;

inline void compress(){
    vector<int> c(26,-1);
    for(int i=0;i<n;i++){
        if(c[s[i]-'a']==-1)c[s[i]-'a']=m++;
        v.push_back(c[s[i]-'a']);
    }
    //cerr<<"v:";for(auto i:v)cerr<<i<<",";cerr<<endl;
}

inline int f(vector<int>& cnt){
    __int128_t h=0;
    for(auto i:cnt){
        h=(b*h+i)%MOD;
    }
    return h;
}

signed main(void){
    cin>>s;
    n=s.size();
    compress();


    vector<int> cnt(m,0);
    mp[0]=1;
    for(int i=0;i<n;i++){
        cnt[v[i]]++;
        int mn=*min_element(cnt.begin(),cnt.end());
        for(auto& i:cnt)i-=mn;
        int h=f(cnt);
        //cerr<<"cnt:";for(auto i:cnt)cerr<<i<<",";cerr<<endl;
        //cerr<<"h:"<<h<<endl;
        ans+=mp[h];
        //cerr<<"ans,+:"<<ans<<","<<mp[h]<<endl;
        mp[h]++;
        //cerr<<endl;
    }

    cout<<ans<<endl;
}
