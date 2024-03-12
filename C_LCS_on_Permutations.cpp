#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N], c[N], pos[N];
vector<int> lis;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		// pos is the inverse of a
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) { cin >> b[i]; }
	for (int i = 1; i <= n; ++i) { c[i] = pos[b[i]]; }

	for (int i = 1; i <= n; ++i) {
		int p = lower_bound(begin(lis), end(lis), c[i]) - begin(lis);
		if (p == lis.size()) lis.push_back(c[i]);
		else lis[p] = c[i];
	}
	cout << lis.size() << '\n';
}
