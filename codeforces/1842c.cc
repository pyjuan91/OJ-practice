#include <bits/stdc++.h>
using namespace std;
int a[200005], dp[200005], res[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i <= n + 4; i++) res[i] = INT32_MAX;
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = min(dp[i - 1] + 1, res[a[i]]);
			res[a[i]] = min(dp[i - 1], res[a[i]]);
		}
		cout << n - dp[n] << '\n';
	}
	return 0;
}
