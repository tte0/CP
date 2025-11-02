// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h> 
#define int int_fast64_t
using namespace std;
///////////////////////////////////////////////////////////
int n,k;

signed main(void){
    cin>>n>>k;
    int last=0,a=0,b=0;
    bool person=1;//0 alice 1 bob;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        if(person==1){
            a+=(x-last+1)/2;
            b+=(x-last)/2;
        }
        else{
            a+=(x-last)/2;
            b+=(x-last+1)/2;
        }

        //cerr<<"a,b:"<<a<<" "<<b<<endl;
        //cerr<<"last,person:"<<last<<" "<<person<<endl;
        if((x-last)&1)person^=1;

        //cerr<<"a,b:"<<a<<" "<<b<<endl;
        //cerr<<"last,person:"<<last<<" "<<person<<endl;
        //until here normal

        a+=(person==0?-1:+1);
        b+=(person==1?-1:+1);

        person^=1;

        last=x;

        //cerr<<"a,b:"<<a<<" "<<b<<endl;
        //cerr<<"last,person:"<<last<<" "<<person<<endl;
        //cerr<<endl;
    }

    if(person==1){
        a+=(n-last+1)/2;
        b+=(n-last)/2;
    }
    else{
        a+=(n-last)/2;
        b+=(n-last+1)/2;
    }


    cout<<a<<" "<<b<<endl;
}
