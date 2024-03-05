#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll MAX_D = 1e18;
struct Coord {
  public:
	int x, y;
};

ll dist(const Coord &a, const Coord &b) {
	int x = (a.x - b.x);
	int y = (a.y - b.y);

	return (x * x) + (y * y);
}

int main() {
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);

	int h, g;
	cin >> h >> g;

	vector<Coord> hs(h), gs(g);

	for (int i = 0; i < h; i++) { cin >> hs[i].x >> hs[i].y; }

	for (int i = 0; i < g; i++) { cin >> gs[i].x >> gs[i].y; }

	/*
	 * min_dist[i][j][k] represents the minimum distance for
	 * Farmer John to visit the first i Holsteins and the first
	 * j Guernseys, given that Farmer John is currently at
	 * k (0: ith Holstein, 1: ith Guernsey)
	 */

	// set default value to arbitrarily large integer to prevent overflow
	vector<vector<vector<ll>>> min_dist(
	    h + 1, vector<vector<ll>>(g + 1, vector<ll>(2, MAX_D)));

	min_dist[1][0][0] = 0;

	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= g; j++) {
			if (i > 1) {
				min_dist[i][j][0] =
				    min(min_dist[i][j][0],
				        min_dist[i - 1][j][0] + dist(hs[i - 2], hs[i - 1]));
			}

			if (j > 1) {
				min_dist[i][j][1] =
				    min(min_dist[i][j][1],
				        min_dist[i][j - 1][1] + dist(gs[j - 2], gs[j - 1]));
			}

			if (i > 0 && j > 0) {
				min_dist[i][j][0] =
				    min(min_dist[i][j][0],
				        min_dist[i - 1][j][1] + dist(hs[i - 1], gs[j - 1]));
				min_dist[i][j][1] =
				    min(min_dist[i][j][1],
				        min_dist[i][j - 1][0] + dist(hs[i - 1], gs[j - 1]));
			}
		}
	}

	cout << min_dist[h][g][0] << endl;
}