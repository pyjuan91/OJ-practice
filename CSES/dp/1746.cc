#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, res = 0;
	cin >> n >> m;
	vector<int> a(n);
	vector<vector<int>> dp(n, vector<int>(m + 1, 0));
	for (auto& x : a) cin >> x;
	if (a[0] == 0) fill(dp[0].begin(), dp[0].end(), 1);
	else dp[0][a[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != 0) {
			dp[i][a[i]] += dp[i - 1][a[i]];
			if (a[i] - 1 >= 1)
				dp[i][a[i]] += dp[i - 1][a[i] - 1];
			if (a[i] + 1 <= m)
				dp[i][a[i]] += dp[i - 1][a[i] + 1];
			dp[i][a[i]] %= mod;
		}
		else {
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i - 1][j];
				if (j - 1 >= 1) dp[i][j] += dp[i - 1][j - 1];
				if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
		}
	}
	for (int j = 1; j <= m; j++)
		res = (res + dp[n - 1][j]) % mod;
    cout << res;
	return 0;
}