#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2")
#define int ll
using namespace std;
typedef int_fast64_t ll;
const int LIMIT=1e10;
vector<string> alphabet;

// Create a global random engine seeded with the current time.
std::mt19937 rng(static_cast<unsigned>(
    std::chrono::steady_clock::now().time_since_epoch().count()));

inline int hashString(const string& s,const int& base,const int& mod){
    int ans=0,n=s.size();
    for(int i=0;i<n;i++){
        ans=(base*ans+(s[i]-'a'))%mod;
    }
    return ans;
}

inline void generateString(const vector<string>& alphabet, string& s, const int length) {
    s.clear();
    s.reserve(length);  // Pre-allocate memory for the string.
    // Set up a uniform distribution over valid indices.
    uniform_int_distribution<int> dist(0, static_cast<int>(alphabet.size()) - 1);
    for (int i = 0; i < length; i++) {
        s.append(alphabet[dist(rng)]);
    }
}

inline void shorten(string &s, string &q) {
    // Remove common prefix
    int pref = 0, n = min(s.size(), q.size());
    while (pref < n && s[pref] == q[pref])
        pref++;
    // Erase the common prefix from both strings
    s.erase(0, pref);
    q.erase(0, pref);

    // Remove common suffix
    int suff = 0, sn = min(s.size(), q.size());
    while (suff < sn && s[s.size() - 1 - suff] == q[q.size() - 1 - suff])
        suff++;
    // Erase the common suffix from both strings
    s.erase(s.size() - suff, suff);
    q.erase(q.size() - suff, suff);
}

inline vector<string> generateAlphabet(const vector<string>& alphabet, const int& base, const int& mod, const int& n){
    unordered_map<int, string> mp;
    mp.reserve(1<<16);  // Pre-reserve space to reduce rehashing overhead
    mp.max_load_factor(0.25);
    int hash;
    string s, q; 
    while (true) {
        generateString(alphabet, s, n);
        hash = hashString(s, base, mod);
        
        auto it = mp.find(hash);
        if (it != mp.end() && it->second != s) {
            q = it->second;
            break;
        }
        if (s.size() * mp.size() < LIMIT)
            mp[hash] = s;
    }
    
    shorten(s, q);
    
    return {s, q};
}



int32_t main(void){
    clock_t start=clock();
    string _="a";
    for(int i=0;i<26;i++){
        alphabet.push_back(_);
        _[0]++;
    }
    //
    vector<tuple<int,int>> input={
        {9973,1e9+9},
    };
    //
    int n=input.size();
    for(int i=0;i<n;i++){
        cerr<<"i:"<<i<<endl;
        auto [x,y]=input[i];
        
        if(i==0)alphabet=generateAlphabet(alphabet,x,y,7);
        if(i==1)alphabet=generateAlphabet(alphabet,x,y,20);
        if(i==2)alphabet=generateAlphabet(alphabet,x,y,20);
        if(i==3)alphabet=generateAlphabet(alphabet,x,y,20);
    }

    alphabet[0].push_back('a');
    alphabet[1].push_back('a');
    alphabet[0].insert(alphabet[0].begin(),'a');
    alphabet[1].insert(alphabet[1].begin(),'a');
    
    string s=alphabet[0];
    string q=alphabet[1];
    reverse(alphabet[0].begin(),alphabet[0].end());
    reverse(alphabet[1].begin(),alphabet[1].end());
    string _s=alphabet[0];
    string _q=alphabet[1];

    freopen("normal.txt","w",stdout);
    cout<<s<<endl<<q<<endl;

    freopen("reverse.txt","w",stdout);
    cout<<_s<<endl<<_q<<endl;


    freopen("combined.txt","w",stdout);
    cout<<s<<_s<<s<<_q<<endl<<q<<_q<<endl;

    cerr<<fixed<<setprecision(3)<<double(clock()-start)/double(CLOCKS_PER_SEC)<<" s"<<endl;
}
