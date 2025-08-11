// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,x;
vector<int> h,s,k;

struct wtf{
    priority_queue<int> in,out;
    wtf(){
        clear();
    }
    void insert(int x){
        //cerr<<"insert:"<<x<<endl;
        in.push(x);
    }
    void erase(int x){
        //cerr<<"erase:"<<x<<endl;
        out.push(x);
        balance();
        //cerr<<"erase ok"<<endl;
    }
    void balance(){
        //cerr<<"balance:"<<x<<endl;
        while(out.size() && in.size() && out.top()==in.top()){
            in.pop();
            out.pop();
        }
        assert(!(out.size() && in.empty()));
        assert(!(out.size() && out.top()>=in.top()));
        //cerr<<"balance ok"<<endl;
    }
    int max(){
        return in.top();
    }
    void clear(){
        in={};
        out={};
        in.push(-1e9-9);
    }
};

signed main(void){
    cin>>n>>x;
    h.resize(n);
    s.resize(n);
    k.resize(n);
    for(auto& i:h)cin>>i;
    for(auto& i:s)cin>>i;
    for(auto& i:k)cin>>i;

    vector<int> dp(x+1,-1e9),old_dp(x+1,-1e9);
    wtf st;
    old_dp[0]=0;
    for(int i=0;i<n;i++){
        //cerr<<"i:"<<i<<endl;
        int price=h[i],page=s[i],copy=k[i];
        if(price>x)continue;
        st.clear();
        for(int j=0;j<price;j++){
            //cerr<<"j:"<<j<<endl;
            for(int k=0;k*price+j<=x;k+=1){
                //cerr<<"i,j,k:"<<i<<","<<j<<","<<k<<endl;
                if(k>copy){
                    st.erase(old_dp[price*(k-copy-1)+j]-(k-copy-1)*page);
                }
                st.insert(old_dp[price*k+j]-k*page);
                dp[price*k+j]=st.max()+k*page;
            }
        }
        swap(dp,old_dp);
        //for(auto i:old_dp)cerr<<i<<" ";cerr<<endl;
    }

    int mx=0;
    for(auto i:old_dp)mx=max(mx,i);
    cout<<mx;
}
