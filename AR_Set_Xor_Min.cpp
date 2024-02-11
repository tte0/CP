    #pragma GCC target("popcnt,abm,mmx,avx,avx2,lzcnt,bmi,bmi2,fma,sse,sse2,sse3,sse4,sse4.1,sse4.2,tune=native")
    #pragma GCC optimize("-fipa-sra,-fgcse-lm,-fgcse,inline,unroll-all-loops,no-stack-protector,O3,fast-math,Ofast")
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
    int n,m,k,t,q,x,y,ans,expo[59];
    str s;
    vi v;

    struct Node{
        struct Node *zeroNode=NULL;
        struct Node *oneNode=NULL;
        int count=0;
    };
    Node *root=new Node();

    inline void insert(int x){
        Node *travel=root;
        int flag=0;
        for(int i=31;i>=0;i--){
            if((x&expo[i])==0){
                if(travel->zeroNode==NULL){flag=1;break;}
                travel=travel->zeroNode;
            }
            else{
                if(travel->oneNode==NULL){flag=1;break;}
                travel=travel->oneNode;
            }
        }
        if(flag==0)return;
        travel=root;
        travel->count++;
        for(int i=31;i>=0;i--){
            if((x&expo[i])==0){
                if(travel->zeroNode==NULL)travel->zeroNode=new Node();
                travel=travel->zeroNode;
            }
            else{
                if(travel->oneNode==NULL)travel->oneNode=new Node();
                travel=travel->oneNode;
            }
            travel->count++;
        }
    }

    inline void erase(int x){
        Node *travel=root;
        for(int i=31;i>=0;i--){
            if((x&expo[i])==0){
                if(travel->zeroNode==NULL)return;
                travel=travel->zeroNode;
            }
            else{
                if(travel->oneNode==NULL)return;
                travel=travel->oneNode;
            }
        }
        travel=root;
        travel->count--;
        for(int i=31;i>=0;i--){
            if((x&expo[i])==0){
                travel=travel->zeroNode;
            }
            else{
                travel=travel->oneNode;
            }
            travel->count--;
        }
    }

    inline void query(int x){
        Node *travel=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            //cerr<<i<<"->";
            if((x&expo[i])){
                if(travel->oneNode!=NULL && travel->oneNode->count>0){
                    travel=travel->oneNode;
                    //cerr<<1<<endl;
                }
                else{
                    travel=travel->zeroNode;
                    ans+=expo[i];
                    //cerr<<0<<endl;
                }
            }
            else{
                if(travel->zeroNode!=NULL && travel->zeroNode->count>0){
                    travel=travel->zeroNode;
                    //cerr<<0<<endl;
                }
                else{
                    travel=travel->oneNode;
                    ans+=expo[i];
                    //cerr<<1<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }

    int32_t main(void){
        expo[0]=1;
        for(int i=1;i<=31;i++){
            expo[i]=2*expo[i-1];
        }
        fastio;
        cin>>t;
        while(t--){
            cin>>s>>x;
            if(s=="0")insert(x);
            if(s=="1")erase(x);
            if(s=="2")query(x);
        }
    }