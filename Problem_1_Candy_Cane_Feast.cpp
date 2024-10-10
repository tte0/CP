/*
Author: Teoman Ata Korkmaz
*/
#include <bits/stdc++.h> 
#define int ll
using namespace std;
typedef int_fast64_t ll;
int n,m;
vector<int> cow,candy;

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    cow.resize(n);
    candy.resize(m);
    for(int& i:cow)cin>>i;
    for(int& i:candy)cin>>i;

    for(int x:candy){
        int l=0;
        for(int& i:cow){
            int y=min(x,max(i,l));
            i+=y-l;
            l=y;
            if(l==x)break;
        }
        //for(int i:cow)cerr<<i<<' ';cerr<<endl;
    }

    for(int i:cow)cout<<i<<'\n';
}
