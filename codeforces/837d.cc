#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, k, x;
	cin >> n >> k;
	vector<int> five(n + 1, 0), two(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		while (x % 5 == 0) {
			x /= 5;
			five[i] += 1;
		}
		while (x % 2 == 0) {
			x /= 2;
			two[i] += 1;
		}
	}
	vector<vector<int>> dp(k + 1, vector<int>(65 * 205, -1));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, k); j > 0; j--) {
			for (int u = 65 * 205 - 1; u >= 0; u--) {
				if (u - two[i] >= 0 && dp[j - 1][u - two[i]] >= 0) {
					dp[j][u] = max(
					  dp[j][u], dp[j - 1][u - two[i]] + five[i]);
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 65 * 205; i++)
		res = max(res, min(i, dp[k][i]));
	cout << res;
	return 0;
}