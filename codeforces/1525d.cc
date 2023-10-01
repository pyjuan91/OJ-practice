#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, cnt = 0;
	cin >> n;
	vector<int> a(n + 1, 0), org;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) org.push_back(i);
	}
	if (org.size() == 0) {
		cout << 0 << '\n';
		return 0;
	}
	vector<vector<int>> dp(n + 1, vector<int>(org.size() + 1, 1e18));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= org.size(); j++) {
			if (a[i] == 1 || j == 0) dp[i][j] = dp[i - 1][j];
			else if (j)
				dp[i][j] = min(
				  dp[i - 1][j], dp[i - 1][j - 1] + abs(org[j - 1] - i));
		}
	}
	cout << dp[n][org.size()] << '\n';
	return 0;
}
