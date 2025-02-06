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

inline vector<string> generateAlphabet(const vector<string>& alphabet, const int& base, const int& mod) {
    unordered_map<int, string> mp;
    mp.reserve(1<<16);  // Pre-reserve space to reduce rehashing overhead
    mp.max_load_factor(0.25);
    int n = 25, hash;
    string s, q; 
    while (true) {
        s.clear();
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
    string _="a";
    for(int i=0;i<26;i++){
        alphabet.push_back(_);
        _[0]++;
    }
    //
    int n;
    cout<<"How many hash: ";cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cout<<"base: ";cin>>x;
        cout<<"mod : ";cin>>y;
        
        alphabet=generateAlphabet(alphabet,x,y);
    }

    freopen("normal.txt","w",stdout);
    for(auto& i:alphabet)cout<<i<<endl;

    for(auto& i:alphabet)reverse(i.begin(),i.end());

    freopen("reverse.txt","w",stdout);
    for(auto& i:alphabet)cout<<i<<endl;
}
