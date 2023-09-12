#include <bits/stdc++.h>
#define int long long
using namespace std;
int len[100005], up[100005], down[100005], dp[100005], diff[100005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> len[i];
		for (int i = 1; i <= n; i++) cin >> up[i];
		for (int i = 1; i <= n; i++) cin >> down[i];
		for (int i = 1; i <= n; i++)
			diff[i] = llabs(up[i] - down[i]);
		for (int i = 1; i <= n; i++) dp[i] = 0;
		int res = 0;
		for (int i = n; i > 1; i--) {
			if (i < n && down[i + 1] != up[i + 1]) {
				dp[i] = dp[i + 1] + len[i] - 2 * (diff[i + 1])
					  + 1 + diff[i];
			}
			dp[i] = max(dp[i], len[i] + 1 + diff[i]);
			res = max(res, dp[i]);
		}
		cout << res << '\n';
	}
	return 0;
}
