#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, a[205], dp[205][305];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < 205; i++)
			for (int j = 0; j < 305; j++) dp[i][j] = 1e18;
		for (int j = 0; j < 305; j++) dp[0][j] = abs(a[0] - j);
		for (int i = 1; i < n; i++) {
			for (int j = i; j < 305; j++) {
				for (int k = j + 1; k < 305; k++) {
					dp[i][k]
					  = min(dp[i][k], dp[i - 1][j] + abs(a[i] - k));
				}
			}
		}
		int ans = 1e18;
		for (int j = 0; j < 305; j++)
			ans = min(ans, dp[n - 1][j]);
		cout << ans << '\n';
	}
	return 0;
}
