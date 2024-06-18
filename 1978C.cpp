#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k > n * (n - 1) / 2 || k < 0) {
            cout << "No" << endl;
        } else if (k == 0) {
            cout << "Yes" << endl;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << "Yes" << endl;
            vector<int> p(n);
            for (int i = 0; i < n; i++) {
                p[i] = i + 1;
            }
            int diff = k;
            for (int i = 1; i < n; i++) {
                if (diff >= 2) {
                    diff -= 2;
                    swap(p[i], p[i - 1]);
                } else {
                    break;
                }
            }
            if (diff == 1) {
                swap(p[0], p[1]);
            }
            for (int i = 0; i < n; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
