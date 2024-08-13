#include "magicnr.h"

int get_number(int n)
{
	int l=1,r=n;
	while(l<=r){
		int m=(l+r)>>1;
		int t=guess(m);
		if(t==0)return m;
		if(t==1)l=m+1;
		else r=m-1;
	}
	return l;
}
