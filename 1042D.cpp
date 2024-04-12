/*
MIT License
 
Copyright (c) 2024 tte0 (teomana,teoata17)
 
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
 
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma GCC optimize("O3,fast-math,unroll-all-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int ll
#define endl '\n'
#define spc ' '
#define pb push_back
#define all(x) x.begin(),x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
#define fileio freopen("out.txt","w",stdout);freopen("in.txt","r",stdin)#define ordered_set<T> tree(T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update)
#define ordered_set tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
typedef int_fast64_t ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////////////////////////////////////////
int n,k;
vi v;
 
inline void solve(void){
    cin>>n>>k;
    v.resize(n);
    for(auto &i:v) cin>>i;
    for(int i=1;i<n;i++) v[i]+=v[i-1];
    int ans=0;
    ordered_set st;
    st.insert({0,0});
    for(int i=0;i<n;i++){
        ans+=st.size()-st.order_of_key({v[i]-k,1});   
        st.insert({v[i],-i});
    }
    cout<<ans<<endl;
}
 
int32_t main(void){
    fastio;
    solve();
}