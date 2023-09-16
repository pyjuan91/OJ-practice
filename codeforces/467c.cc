#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n + 1), end_su(n + 1, 0);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) end_su[m] += a[i];
	for (int i = m + 1; i <= n; i++)
		end_su[i] = end_su[i - 1] + a[i] - a[i - m];
	for (int i = m; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + end_su[i]);
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}
