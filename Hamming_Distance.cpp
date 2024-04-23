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
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
#pragma GCC optimize("-fipa-sra,-fgcse-lm,-fgcse,inline,unroll-all-loops,no-stack-protector,O3,fast-math,Ofast")
#include <bits/stdc++.h>
#define int i32
#define pb push_back
#define e2(x) (1LL<<(x))
#define popcnt(x) __builtin_popcount(x)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
using namespace std;
typedef int32_t i32;
typedef vector<int> vi;

i32 main(void){
    fastio;
    int n,m,ans=INT32_MAX;
    cin>>n>>m;
    int v[n];
    for(int i=0;i<n;i++){
        char c;
        int x=0;
        for(int j=0;j<m;j++){
            cin>>c;
            x=(x<<1)+(c=='1');
        }
        cerr<<"x: "<<x<<endl;
        for(int j=0;j<i;j++)ans=min(ans,popcnt(x^v[j]));
        v[i]=x;
    }

    //cerr<<"v: ";for(auto x:v)cerr<<x<<' ';cerr<<endl;
    cout<<ans<<endl;
}
