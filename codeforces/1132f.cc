#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
	for (int len = 1; len <= n; len++) {
		if (len == 1) {
			for (int i = 0; i <= n; i++) dp[i][i] = 1;
			continue;
		}
		for (int left = 1; left + len - 1 <= n; left++) {
			int right = left + len - 1;
			if (s[left] == s[left + 1])
				dp[left][right]
				  = min(dp[left][right], dp[left + 1][right]);
			else
				dp[left][right]
				  = min(dp[left][right], dp[left + 1][right] + 1);
			for (int mid = left + 1; mid <= right; mid++) {
				if (s[left] == s[mid])
					dp[left][right] = min(
					  dp[left][right],
					  dp[left + 1][mid - 1] + dp[mid][right]);
			}
		}
	}
	cout << dp[1][n] << '\n';
	return 0;
}
