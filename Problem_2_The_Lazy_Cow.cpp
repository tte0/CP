// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=6*(400+3);
///////////////////////////////////////////////////////////
int n,k,pref[N][N],pref2[N][N];
vector<vector<int>> v;

inline int DeezNuts(int r,int u,int l,int d){
    cerr<<"d1: "<<u<<","<<l<<" "<<d<<","<<r<<" ";
    l=l/2+N/2;
    u=u/2+N/2;
    r=r/2+N/2;
    d=d/2+N/2;
    int t=pref[d][r]-pref[d][l-1]-pref[u-1][r]+pref[u-1][l-1];
    cerr<<t<<endl;
    return t;
}

inline int DeezNuts2(int r,int u,int l,int d){
    cerr<<"d2: "<<u<<","<<l<<" "<<d<<","<<r<<" ";
    l=l/2+N/2;
    u=u/2+N/2;
    r=r/2+N/2;
    d=d/2+N/2;
    int t=pref2[d][r]-pref2[d][l-1]-pref2[u-1][r]+pref2[u-1][l-1];
    cerr<<t<<endl;
    return t;
}

signed main(void){
    cin>>n>>k;
    v.resize(n,vector<int>(n));
    for(auto& t:v)for(auto& i:t)cin>>i;

    //[i-j][i+j] [i-j+1][i+j]

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            (i%2==j%2?pref:pref2)[(i-j)/2+N/2][(i+j)/2+N/2]=v[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i)
                pref[i][j]+=pref[i-1][j],
                pref2[i][j]+=pref2[i-1][j];
            if(j)
                pref[i][j]+=pref[i][j-1],
                pref2[i][j]+=pref2[i][j-1];
            if(i && j)
                pref[i][j]-=pref[i-1][j-1],
                pref2[i][j]-=pref2[i-1][j-1];
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,
                ((i+k)%2==j%2?DeezNuts:DeezNuts2)(i-(j-k),i+(j-k),i-(j+k),i+(j+k))
                +
                ((i+k)%2==j%2?DeezNuts2:DeezNuts)(i-(j-(k-1)),i+(j-(k-1)),i-(j+(k-1)),i+(j+(k-1)))
            );
        }
        cerr<<endl;
    }

    cout<<ans<<endl;
}
