// Author: Teoman Ata Korkmaz
#include <bits/stdc++.h>
#define int int_fast64_t
using namespace std;

int n, fp[21];

inline int g(int i, int d, int x) {
    // number of possible answers when:
    // the number has "d" digits,
    // processed "i" digits from left & right
    // "x" amount left to produce diff

    // possible answer when:
    // there is no digits to process 
    // no diff to produce
    if (d <= 2 * i + 1) return !x;

    // coefficent for the digit
    int b = fp[d - i - 1] - fp[i];

    //max difference can be made with digits is 9
    if (x / b > 9) return 0;


    int under_shoot = (10 - x / b - !i) * g(i + 1, d, x % b);
    int over_shoot = (10 - (x / b + 1) - !i) * g(i + 1, d, abs(x % b - b));

    return under_shoot + over_shoot;
}

signed main() {
    cin >> n;

    fp[0] = 1;
    for (int i = 1; i < 21; i++) //10s powers
        fp[i] = fp[i - 1] * 10;

    int ans = 0;
    // calculating for all possible NoD 
    for (int i = 1; i <= 20; i++) {
        // one free digit when NoD is odd
        int factor = (i & 1) ? 10 : 1;

        ans += g(0, i, n) * factor;
    }

    cout << ans << endl;
}
