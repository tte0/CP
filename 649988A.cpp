// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
constexpr int N=2e5+5;
///////////////////////////////////////////////////////////
int n,m,q,row[N],col[N],ans;
vector<vector<int>> v;

bool isjustis(int x,int y){
    return row[x]==y && col[y]==x;
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>q;    
    v.resize(n,vector<int>(m));
    for(auto& t:v)for(auto& i:t)cin>>i;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][row[i]]<v[i][j])row[i]=j;
            if(v[col[j]][j]<v[i][j])col[j]=i;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=isjustis(i,j);
        }
    }

    //cerr<<ans<<endl<<endl;

    while(q--){
        /*cerr<<" ";for(int j=0;j<m;j++)cerr<<col[j]<<" ";cerr<<endl;
        for(int i=0;i<n;i++)cerr<<row[i]<<endl;cerr<<endl;*/

        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;

        bool r=v[x][row[x]]<w,c=v[col[y]][y]<w;
        
        if(isjustis(x,y)){
            goto answer;
        }
        if(r)ans-=isjustis(x,row[x]);
        if(c)ans-=isjustis(col[y],y);
        if(r)row[x]=y;
        if(c)col[y]=x;

        ans+=isjustis(x,y);

        answer:
        v[x][y]=w;

        cout<<ans<<endl;
        //cerr<<endl;
    }
}
