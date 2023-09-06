#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		auto is_prime = [&](int x) {
            if (x < 2) return false;
			for (int i = 2; i * i <= x; ++i) {
				if (x % i == 0) return false;
			}
			return true;
		};
		if (!is_prime(n)) {
			for (int j = 0; j < m; j++) {
				for (int i = 0; i < n; i++)
					a[i][j] = j * n + i + 1;
			}
		}
		else if (!is_prime(m)) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					a[i][j] = i * m + j + 1;
			}
		}
		else {
			int x = 0;
			for (int i = 0; i < n; i += 2) {
				for (int j = 0; j < m; j++) a[i][j] = ++x;
			}
			for (int i = 1; i < n; i += 2) {
				for (int j = 0; j < m; j++) a[i][j] = ++x;
			}
		}
		// auto check = [&]() {
		// 	for (int i = 0; i < n - 1; i++) {
		// 		for (int j = 0; j < m - 1; j++) {
		// 			int diff = abs(a[i][j] - a[i + 1][j]);
		// 			if (is_prime(diff)) return false;
		// 			diff = abs(a[i][j] - a[i][j + 1]);
		// 			if (is_prime(diff)) return false;
		// 		}
		// 	}
		// 	return true;
		// };
        // if(!check()) cout << "NO\n";
        // else cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; ++j) cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}
