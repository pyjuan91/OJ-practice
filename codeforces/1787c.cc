#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, s, num;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		vector<int> mi(n + 1), ma(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> num;
			if (i == 1 || i == n) {
				mi[i] = ma[i] = num;
				continue;
			}
			if (num <= s) mi[i] = 0, ma[i] = num;
			else if (num - s > s) mi[i] = s, ma[i] = num - s;
			else mi[i] = num - s, ma[i] = s;
		}
		vector<vector<int>> dp(n + 1, vector<int>(2, INT64_MAX));
		dp[1][0] = dp[1][1] = 0;
		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(
			  dp[i - 1][0] + mi[i] * ma[i - 1],
			  dp[i - 1][1] + mi[i] * mi[i - 1]);
			dp[i][1] = min(
			  dp[i - 1][0] + ma[i] * ma[i - 1],
			  dp[i - 1][1] + ma[i] * mi[i - 1]);
		}
		cout << min(dp[n][0], dp[n][1]) << '\n';
	}
	return 0;
}