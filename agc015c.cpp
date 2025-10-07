// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2003;
///////////////////////////////////////////////////////////
int n,m,q,prefu[N][N],prefl[N][N],prefb[N][N];
vector<string> s;
vector<vector<int>> v;

inline int queryu(int u,int l,int d,int r){
    return prefu[d][r]-prefu[d][l-1]-prefu[u][r]+prefu[u][l-1];
}

inline int queryl(int u,int l,int d,int r){
    return prefl[d][r]-prefl[d][l]-prefl[u-1][r]+prefl[u-1][l];
}

inline int queryb(int u,int l,int d,int r){
    return prefb[d][r]-prefb[d][l-1]-prefb[u-1][r]+prefb[u-1][l-1];
}

signed main(void){
    cin>>n>>m>>q;
    v.resize(n,vector<int>(m));
    s.resize(n);
    for(auto& i:s)cin>>i;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=s[i][j]-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prefb[i+1][j+1]=v[i][j];
            prefu[i+1][j+1]=(i && v[i][j] && v[i-1][j]);
            prefl[i+1][j+1]=(j && v[i][j] && v[i][j-1]);
            if(i)
                prefb[i+1][j+1]+=prefb[i][j+1],
                prefu[i+1][j+1]+=prefu[i][j+1],
                prefl[i+1][j+1]+=prefl[i][j+1];
            if(j)
                prefb[i+1][j+1]+=prefb[i+1][j],
                prefu[i+1][j+1]+=prefu[i+1][j],
                prefl[i+1][j+1]+=prefl[i+1][j];
            if(i && j)
                prefb[i+1][j+1]-=prefb[i][j],
                prefu[i+1][j+1]-=prefu[i][j],
                prefl[i+1][j+1]-=prefl[i][j];
        }
    }

    auto debug=[&](int arr[N][N],string s){
        for(int i=0;i<=n;i++){
            cerr<<s<<": ";
            for(int j=0;j<=m;j++){
                cerr<<arr[i][j]<<",";
            }
            cerr<<endl;
        }
        cerr<<endl;
    };

    //debug(prefb,"prefb");
    //debug(prefu,"prefu");
    //debug(prefl,"prefl");
    

    while(q--){
        int u,l,d,r;
        cin>>u>>l>>d>>r;

        int edge=queryb(u,l,d,r)-(queryu(u,l,d,r)+queryl(u,l,d,r));
        cout<<edge<<endl;
        //cerr<<endl;
    }
}
