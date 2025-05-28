// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////

signed main(void){
    string s;
    cin>>s;
    set<char> st;
    for(char c='a';c<='z';c++)st.insert(c);
    for(auto i:s)st.erase(i);
    cout<<*st.begin()<<endl;
}
