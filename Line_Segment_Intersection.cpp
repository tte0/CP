// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int q;

struct Point{
    int x;
    int y;
};

inline int f(Point p1,Point p2,Point p3){
    if(p1.y>p2.y || (p1.y==p2.y && p2.x<p1.x))return -f(p2,p1,p3);
    if(p1.x==p2.x){
        if(p3.x<p1.x)return -1;
        if(p3.x==p1.x)return 0;
        if(p3.x>p1.x)return 1;
    }
    if(p1.y==p2.y){
        if(p3.y>p1.y)return -1;
        if(p3.y==p1.y)return 0;
        if(p3.y<p1.y)return 1;
    }
    __float128 slope=__float128(p1.y-p2.y)/__float128(p1.x-p2.x);
    __float128 delta_y=p3.y-p1.y;
    __float128 xOnLine=p1.x+delta_y/slope;
    if(p3.x<xOnLine)return -1;
    if(p3.x==xOnLine)return 0;
    if(p3.x>xOnLine)return 1;
    assert(false);
    return 0;
}

inline bool g(Point p1,Point p2,Point p3,Point p4){
    bool ans=f(p1,p2,p3)!=f(p1,p2,p4) && f(p3,p4,p1)!=f(p3,p4,p2);
    ans|=f(p1,p2,p3)==0 || f(p1,p2,p4)==0 || f(p3,p4,p1)==0 || f(p3,p4,p2)==0;
    return ans;
}

signed main(void){
    cin>>q;
    while(q--){
        Point p1,p2,p3,p4;
        cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
        if(g(p1,p2,p3,p4))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
