#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, m, k, a1, ak;
	cin >> t;
	while (t--) {
		cin >> m >> k >> a1 >> ak;
		if (k * ak + a1 >= m) {
			cout << max(0ll, (m - (m / k) * k - a1)) << '\n';
		}
		else {
			int tar = m - k * ak;
			int big = tar / k, remain = tar % k;
			if (a1 <= remain) {
				cout << big + remain - a1 << "\n";
			}
			else {
				a1 -= remain;
				big -= a1 / k;
				cout << big << "\n";
			}
		}
	}
	return 0;
}
