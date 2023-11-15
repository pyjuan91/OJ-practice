#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, res = 0, x, y, c, a[18] = {}, b[18][18] = {},
			 dp[18][1 << 18] = {};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (m == 1) {
		cout << *max_element(a, a + n) << '\n';
		return 0;
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> c;
		b[x - 1][y - 1] = c;
	}
	for (int mask = 1; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) == 1) {
			int i = __builtin_ctz(mask);
			dp[i][mask] = a[i];
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) continue;
			int pre_state = mask ^ (1 << i);
			for (int j = 0; j < n; j++) {
				if (!(pre_state & (1 << j))) continue;
				dp[i][mask] = max(
				  dp[i][mask], dp[j][pre_state] + a[i] + b[j][i]);
			}
			if (__builtin_popcount(mask) == m)
				res = max(res, dp[i][mask]);
		}
	}
	cout << res << '\n';
	return 0;
}
