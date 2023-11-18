#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> p(n + 1), w(n + 1);
		for (int i = 1; i <= n; ++i) cin >> p[i] >> w[i];
		cin >> m;
		int res = 0;
		while (m--) {
			cin >> x;
			vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= x; j++) {
					dp[i][j] = dp[i - 1][j];
					if (j >= w[i])
						dp[i][j] = max(
						  dp[i][j], dp[i - 1][j - w[i]] + p[i]);
				}
			}
			res += *max_element(dp[n].begin(), dp[n].end());
		}
		cout << res << '\n';
	}
	return 0;
}
