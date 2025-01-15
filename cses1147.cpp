// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1003;
///////////////////////////////////////////////////////////
int n,m;
vector<vector<int>> v;

inline int f(vector<int> v){
    int n=v.size();
    vector<int> l(n,-1),r(n,n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(st.size() && v[st.top()]>=v[i])st.pop();
        if(st.size())l[i]=st.top();
        st.push(i);
    }
    while(st.size())st.pop();
    for(int i=n-1;i>=0;i--){
        while(st.size() && v[st.top()]>=v[i])st.pop();
        if(st.size())r[i]=st.top();
        st.push(i);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,v[i]*(r[i]-l[i]-1));
    }

    return ans;
}

signed main(void){
    cin>>n>>m;
    v.resize(n,vector<int>(m));
    for(auto& _:v){
        for(int& i:_){
            char c;
            cin>>c;
            i=(c=='.');
        }
    }

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            if(v[i][j])sum++;
            else sum=0;
            v[i][j]=sum;
        }
    }

    /*for(int i=0;i<n;i++){
        cerr<<"v:";
        for(int j=0;j<m;j++){
            cerr<<v[i][j]<<",";
        }
        cerr<<endl;
    }*/
    
    int ans=0;
    for(int j=0;j<m;j++){
        vector<int> t;
        for(int i=0;i<n;i++)t.push_back(v[i][j]);
        ans=max(ans,f(t));
    }

    cout<<ans<<endl;
}

