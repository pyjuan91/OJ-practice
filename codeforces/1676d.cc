#include <bits/stdc++.h>
#define int long long
using namespace std;
int board[205][205];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> board[i][j];
		int res = 0;
		auto score = [&](int x, int y) {
			int res = 0;
			for (int i = 0; i < n; i++) {
				if (i - x + y >= 0 && i - x + y < m)
					res += board[i][i - x + y];
			}
			for (int i = 0; i < n; i++) {
				if (x + y - i >= 0 && x + y - i < m)
					res += board[i][x + y - i];
			}
			return res - board[x][y];
		};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res = max(res, score(i, j));
			}
		}
		cout << res << '\n';
	}
	return 0;
}
