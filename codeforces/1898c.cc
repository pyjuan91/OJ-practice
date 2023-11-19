#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, k;
	char a[20][20], b[20][20];
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				a[i][j] = b[i][j] = 'R';
			}
		}
		for (int i = 0; i < 20; i += 2) b[i][0] = 'B';

		int base = n + m - 2;
		if (k < base || ((k - base) % 2 == 1)) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";

		if ((k - base) % 4 == 0) b[0][1] = 'B';
		else {
			b[0][0] = b[0][1] = 'R';
			a[0][0] = a[1][0] = 'B';
		}

		for (int j = (n - 1) % 2; j < m; j += 2)
			a[n - 1][j] = 'B';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) cout << b[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}
