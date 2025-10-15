// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=1003;
///////////////////////////////////////////////////////////
int n,m,edges[N];

inline string str(vector<int> v){
    string s(m,'0');
    for(auto i:v)s[i]='1';
    return s;
}

inline int query(string s){
    cout<<"? "<<s<<"\n"<<flush;
    int x;
    cin>>x;
    return x;
}

inline int answer(int x){
    cout<<"! "<<x<<"\n"<<flush; 
    exit(0);
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        edges[i]=query(str({i}));
    }

    vector<int> v(m);
    iota(v.begin(),v.end(),0);
    sort(v.begin(),v.end(),[&](const int& a,const int& b){
        return edges[a]<edges[b];
    });

    int sum=0;
    string s(m,'0');
    for(auto edge:v){
        sum+=edges[edge];
        s[edge]='1';
        
        if(query(s)!=sum){
            sum-=edges[edge];
            s[edge]='0';
        }
    }

    answer(sum);
}
