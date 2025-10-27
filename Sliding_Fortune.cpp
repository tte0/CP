// Author: Teoman Ata Korkmaz
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e3+3;
///////////////////////////////////////////////////////////
int n,m,a,b,arr[N][N],arr2[N][N];
vector<vector<int>> v;

struct mset{
    priority_queue<int> in,out;
    void insert(int x){
        in.push(x);
    }
    void erase(int x){
        out.push(x);
    }
    void balance(){
        while(in.size() && out.size() && in.top()==out.top()){
            in.pop();
            out.pop();
        }
    }
    int top(){
        balance();
        return in.top();
    }
};

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>a>>b;
    v.resize(n,vector<int>(m));
    for(auto& t:v)for(auto& i:t)cin>>i;
    
    for(int i=0;i<n;i++){
        mset st;
        for(int j=0;j<m;j++){
            st.insert(v[i][j]);
            if(0<=j-b)st.erase(v[i][j-b]);
            arr[i][j]=st.top();
        }
    }

    for(int j=0;j<m;j++){
        mset st;
        for(int i=0;i<n;i++){
            st.insert(arr[i][j]);
            if(0<=i-a)st.erase(arr[i-a][j]);
            arr2[i][j]=st.top();
        }
    }

    int ans=0;
    for(int i=a-1;i<n;i++){
        for(int j=b-1;j<m;j++)ans+=arr2[i][j];
    }

    cout<<ans<<endl;
}
