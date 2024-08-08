#include <bits/stdc++.h>
#define N 300005
#define pb push_back
#define pu push
#define INF 1000000007
#define ff first
#define ss second
#define pint pair<int,int>
#define mod 1000000007
#define int ll
#define mp make_pair
using namespace std;
typedef long long ll;

int32_t main()
{
    freopen("user_output.txt","w",stdout);freopen("testcase.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        string str;
        cin>>n>>str;
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='U')
            {
                ans=!ans;
            }
        }
        if(!ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}