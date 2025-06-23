// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int q,x;
string s;
vector<string> a,b;

signed main(void){
    cin>>q;
    while(q--){
        cin>>x>>s;
        if(x==1){
            vector<string> temp;
            for(auto i:b){
                if(s!=string(i,0,s.size()))temp.push_back(i);
            }
            swap(temp,b);
            a.push_back(s);
        }
        else{
            b.push_back(s);
            for(auto i:a){
                if(i==string(s,0,i.size())){
                    b.pop_back();
                    break;
                }
            }
        }
        cout<<b.size()<<endl;
    }
}
