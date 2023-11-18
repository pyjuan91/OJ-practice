#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, l, r, res;
	while (cin >> n && n) {
		cin >> m;
		vector<int> v(m + 2);
		v[0] = 0, v[m + 1] = n;
		for (int i = 1; i <= m; ++i) cin >> v[i];
		vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));
		function<int(int, int)> cost = [&](int i, int j) {
			if (i + 1 == j) return dp[i][j] = 0;
			if (dp[i][j] != -1) return dp[i][j];
			if (i + 2 == j) return dp[i][j] = v[j] - v[i];
			int res = INT_MAX;
			for (int k = i + 1; k < j; k++) {
				res = min(res, cost(i, k) + cost(k, j) + v[j] - v[i]);
			}
			return dp[i][j] = res;
		};
		cout << "The minimum cutting is " << cost(0, m + 1) << ".\n";
	}
	return 0;
}
