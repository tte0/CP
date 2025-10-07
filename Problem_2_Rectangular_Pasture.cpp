// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2500+5;
///////////////////////////////////////////////////////////
int n,X,Y,comp[N][N],pref[N][N];
vector<int> x,y,x_sorted,y_sorted;

signed main(void){
    cin>>n;
    x.resize(n);    
    y.resize(n);    
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];

    x_sorted=x;
    y_sorted=y;
    sort(x_sorted.begin(),x_sorted.end());
    sort(y_sorted.begin(),y_sorted.end());
    x_sorted.resize(unique(x_sorted.begin(),x_sorted.end())-x_sorted.begin());
    y_sorted.resize(unique(y_sorted.begin(),y_sorted.end())-y_sorted.begin());
    for(auto& i:x){
        i=lower_bound(x_sorted.begin(),x_sorted.end(),i)-x_sorted.begin();
    }
    for(auto& i:y){
        i=lower_bound(y_sorted.begin(),y_sorted.end(),i)-y_sorted.begin();
    }

    cerr<<"x:";for(auto i:x)cerr<<i<<",";cerr<<endl;
    cerr<<"y:";for(auto i:y)cerr<<i<<",";cerr<<endl;

    for(int i=0;i<n;i++)comp[x[i]][y[i]]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            pref[i][j]=(j?pref[i][j-1]:0)|comp[i][j];
        }
    }
    
    for(int j=0;j<N;j++){
        for(int i=N-1;i--;){
            pref[i][j]+=pref[i+1][j];
        }
    }

    cerr<<endl;
    for(int i=0;i<=n;i++){
        cerr<<"comp: ";
        for(int j=0;j<=n;j++){
            cerr<<comp[i][j]<<",";
        }
        cerr<<endl;
    }
    cerr<<endl;
    for(int i=0;i<=n;i++){
        cerr<<"pref: ";
        for(int j=0;j<=n;j++){
            cerr<<pref[i][j]<<",";
        }
        cerr<<endl;
    }

    int ans=0;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(comp[i][j]){
                ans+=ans+pref[i][j];
                break;
            }
        }
    }

    cout<<ans<<endl;
}
