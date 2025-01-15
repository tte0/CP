// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,mnx,mny;
vector<tuple<int,int>> v;

signed main(void){
    cin>>n;
    int x,y,a,b;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(!i)a=x,b=y;
        v.push_back({x-a,y-b});
    }

    // for(auto [a,b]:v){
    //     cerr<<"v:"<<a<<","<<b<<endl;
    // }

    int ansx=0,ansy=0,w=0,t=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // cerr<<"i,j:"<<i<<" "<<j<<endl;
            auto [xi,yi]=v[i];
            auto [xj,yj]=v[j];

            if(xi<0)xi*=-1,yi*=-1;
            if(xj<0)xj*=-1,yj*=-1;
            if(xi!=xj){
                int a=yi*(xj/gcd(xi,xj));
                int b=yj*(xi/gcd(xi,xj));

                ansx=gcd(ansx,abs(a-b));
            }
            else{

            }

            if(yi<0)xi*=-1,yi*=-1;
            if(yj<0)xj*=-1,yj*=-1;
            if(yi!=yj){
                int a=xi*(yj/gcd(yi,yj));
                int b=xj*(yi/gcd(yi,yj));

                ansy=gcd(ansy,abs(a-b));
            }
            else{

            }
        }
    }

    // cerr<<"ansx,ansy:"<<ansx<<","<<ansy<<endl;
    cout<<(ansx && ansy ? (ansx/gcd(ansx,ansy))*ansy : -1)<<endl;
}

