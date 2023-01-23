#include <iostream>

#define int long long
using namespace std;

int pwr(int x, int k) {
    int v = 1;
    for (int i = 1; i <= 18; i <<= 1) {
        if (k & i) v *= x;
        x *= x;
    }
    return v;
}

int dig(int k) {
    int n = 1, ans;
    while (k > 9 * n * pwr(10, n - 1)) {
        k -= 9 * n * pwr(10, n - 1);
        n++;
    }
    ans = pwr(10, n - 1) + (k - 1) / n;
    k = (k - 1) % n;
    ans = (ans / pwr(10, n - k - 1)) % 10;
    return ans;
}

signed main() {
    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        cout << dig(k) << "\n";
    }
    return 0;
}