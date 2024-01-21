#include <bits/stdc++.h>
#define eb emplace_back
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define tpl tuple<ll, int, int>
using namespace std;
 
 
 
const int MAX=1e6,base=57;
 
string a,b;
int h[MAX+5],n,hb,k;
 
int main()
{
    cin>>a>>b;
    if(a.size()==b.size())
    {
        if(a==b)
            cout<<"1";
        else cout<<"0";
        exit(0);
    }
    n=a.size();
    a=" "+a;
    k=b.size();
    h[0]=0;
    
    for(int i=1;i<=n;i++)
        h[i]=(h[i-1]*base+(a[i]-'a'));
    int fact=1,cnt=0;
    for(auto x: b)
        hb=hb*base+(x-'a'),fact*=base;
    for(int i=1;i<=n-k+1;i++)
    {
        if(h[i+k-1]-h[i-1]*fact==hb)
            cnt++;
    }
        
    cout<<cnt;
    return 0;
}