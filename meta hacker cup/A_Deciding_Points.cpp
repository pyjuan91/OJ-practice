#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> n >> m;
		cout << "Case #" << kase << ": ";
		// reachable = (m, 0), (m, 1), ..., (m, m - 2), (m + 1, m - 1), (m + 2, m)
		// m, m+1, m+2, ..., 2*m - 2, 2*m, 2*m + 2, 2*m + 4, ...
		if (n >= 2 * m) {
			if (n % 2 == 0) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else if (n >= m and n <= 2 * m - 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
