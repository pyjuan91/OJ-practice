#include <bits/stdc++.h>
using namespace std;
int a[5005], dp[5005][5005] = {};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++) dp[i][j] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = max({0, a[i], dp[i - 1][0] + a[i]});
			for (int j = 1; j <= i; j++)
				dp[i][j] = max(
				  dp[i - 1][j] + a[i], dp[i - 1][j - 1] + a[i] + x);
		}
		int ans = INT32_MIN;
		for (int j = 0; j <= n; j++) {
			for (int i = 1; i <= n; i++)
				ans = max(ans, dp[i][j]);
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}
