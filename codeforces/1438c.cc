#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a[105][105];
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				bool even_row = (i % 2 == 0);
				bool even_col = (j % 2 == 0);
				if (even_row ^ even_col) {
					if (a[i][j] % 2 == 0) a[i][j]++;
				}
				else {
					if (a[i][j] % 2 == 1) a[i][j]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
