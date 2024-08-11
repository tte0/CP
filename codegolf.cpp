#include<cstdio>
int i,j,c,x;int f(int x){return x?x%10+f(x/10):0;}int main(){for(;i++<1e4;c=0){for(j=1,x=i;++j<i;)for(;x%j==0;c+=f(j))x/=j;f(i)^c?:printf("%d\n",i);}}