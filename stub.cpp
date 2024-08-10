#include <bits/stdc++.h>

int solve(int N, std::vector<int> p);

bool ask(int x) {
	printf("? %d ", x);
	fflush(stdout);
	int res;
	int ignore = scanf("%d", &res);
	return res;
}

int main() {
    int n, a, b;
	int ignore = scanf("%d", &n);
    std::vector<int>p(n-1);

	for(int i=0;i<n-1;i++){
        ignore = scanf("%d", &p[i]);
	}

	int res = solve(n, p);
	printf("! %d ", res);
	fflush(stdout);
}

