#pragma GCC optimize("O3,fast-math")
#include <bits/stdc++.h>
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define N (200005)
#define MOD (int(1e9)+7)
#define MOD2 (998244353)
#define MODL (int(1e9)+21)
#define INF (int(4e18))
#define e2(x) (1LL<<(x))
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x*y)/gcd(x,y))
#define smrt(i) (double(sqrt(8*(i)+1)-1)/2)
#define ssum(x) ((x)*((x)+1)/2)
#define isint(x) (ceil((x))==floor((x)))
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define cendl cout<<endl
#define mset(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define dbg(x) cdebug()<<debug(x)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(0)
using namespace std;
typedef long long ll;
typedef long double ldouble;
typedef string str;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<str> vs;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<pair<char,int>> vci;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
/////////////////////////////////////////////////////////////
unordered_map<vs,int> bestmove;

int btoi(const vs& board){
    int ans=0,p=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='.')ans+=p;
            if(board[i][j]=='O')ans+=p;
            p*=3;
        }
    }
    return ans;
}
void printboard(const vs& board){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==0)cout<<".";
            if(board[i][j]==1)cout<<"X";
            if(board[i][j]==2)cout<<"O";
        }
        cout<<endl;
    }
}
vs itob(int x){
    vs board(3,"...");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x%3==1)board[i][j]='X';
            if(x%3==2)board[i][j]='O';
            x/=3;
        }
    }
    return board;
}


iii minimax(vs board,){
    
}

inline void calculateminimax(){
    vs board(3,"...");
    minimax(board);
}

int32_t main(void){

    calculateminimax();


    str s="-1";
    cout<<"who starts first (P/R): ";
    while(s!="P" && s!="R"){
        cin>>s;
    }
    cout<<s<<" starts first";
    if(s=="P");
}
