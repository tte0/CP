// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
mt19937 mt;

template <typename T>
struct mset{
    priority_queue<T> in,out;
    void insert(const T& x){
        in.push(x);
    }
    void erase(const T& x){
        out.push(x);
    }
    void balance(){
        while(in.size() && out.size() && in.top()==out.top()){
            in.pop();
            out.pop();
        }
    }
    T top(){
        balance();
        return in.top();
    }
};

vector<int> p;
int n;

inline chrono::milliseconds test_mset(int n){
    vector<int> v(n);
    iota(v.begin(),v.end(),0);

    auto start = chrono::high_resolution_clock::now();
    
    // your code here
    return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);

}

signed main(void){
    
}
