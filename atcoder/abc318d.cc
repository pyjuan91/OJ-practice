#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> d(n, vector<int>(n));
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			cin >> d[i][j], d[j][i] = d[i][j];
	}
	vector<int> dp((1 << n) + 1, 0);
	for (int mask = 0; mask < (1 << n); mask++) {
		int sel = -1;
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) {
				sel = i;
				break;
			}
		}
		if (sel == -1) continue;
		for (int i = 0; i < n; i++) {
			if (i == sel) continue;
			if ((1 << i) & mask) continue;
			int new_mask = mask | (1 << sel) | (1 << i);
			dp[new_mask] = max(dp[new_mask], dp[mask] + d[sel][i]);
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}