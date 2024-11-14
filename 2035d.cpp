// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int MOD=1e9+7;
///////////////////////////////////////////////////////////
int n;
vector<int> v;

inline void debug(stack<tuple<int,int>> st){
    while(st.size()){
        auto [a,b]=st.top();
        cerr<<"["<<a<<","<<b<<"]"<<endl;
        st.pop();
    }
    cerr<<endl;
}

inline int fp(int b,int p){
    int ans=1;
    while(p){
        if(p&1)ans=(ans*b)%MOD;
        b=(b*b)%MOD;
        p>>=1;
    }
    return ans;
}

inline bool isbigger(int a,int x,int b,int y){
    if(x<y)return !isbigger(b,y,a,x);
    if(x-y>32)return true;
    return (a<<(x-y))>b;
}

inline void solve(){
    cin>>n;
    v.resize(n);
    for(auto& i:v)cin>>i;

    int sum=0;
    stack<tuple<int,int>> st;// {val,cnt}
    for(int i=0;i<n;i++){
        int x=v[i],cnt=0;
        while(st.size()){
            auto [val,c]=st.top();
            if(isbigger(val,0,x,cnt))break;
            cnt+=c;
            sum-=(fp(2,c)-1)*val%MOD;
            sum=(sum+MOD)%MOD;
            st.pop();
        }
        while((x&1)==0){
            cnt++;
            x>>=1;
        }
        sum+=fp(2,cnt)*x;
        sum%=MOD;
        st.push({x,cnt});

        cout<<sum<<" ";
        //debug(st);
    }
    cout<<endl;
    // cerr<<endl;
}

signed main(void){
    int t;
    cin>>t;
    while(t--)solve();
}

