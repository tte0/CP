#include<stdio.h>
int i;
int main(){
    for(int cnt=0,x=i;i++<1e3;){
        while(x=(x&1?3*x+1:x/2)^1)cnt++;
        printf("%d\n",cnt);
    }
}