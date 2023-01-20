#include <cmath>
#include <iostream>

using namespace std;

long long solve(int x, int y) {
    int leading = max(x, y);
    long long res = 1LL * leading * leading;
    if (res % 2 == 1) res -= x - 1 + leading - y;
    else res -= y - 1 + leading - x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}