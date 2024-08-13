#include "magicnr.h"
#include <stdio.h>

static int s;

int guess(int a) {
	printf("? %d\n", a);
	if (s > a) return 1;
	if (s < a) return -1;
	return 0;
}

int main() {
	int n, r;
	scanf("%d %d", &n, &s);

	r = get_number(n);
	printf("! %d\n", r);
	return 0;
}
