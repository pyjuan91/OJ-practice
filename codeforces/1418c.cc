#include <bits/stdc++.h>
using namespace std;
int chaewon(int n, vector<int> &a) {
	if (n <= 2) return a[0];
	vector<vector<int>> dp(n, vector<int>(2, 2e9));
	dp[0][0] = dp[1][1] = a[0];
	dp[1][0] = a[0] + a[1];
	for (int i = 2; i < n; i++) {
		dp[i][0]
		  = min(dp[i - 2][1] + a[i - 1] + a[i], dp[i - 1][1] + a[i]);
		dp[i][1] = min(dp[i - 2][0], dp[i - 1][0]);
	}
	return min(dp[n - 1][0], dp[n - 1][1]);
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		cout << chaewon(n, a) << "\n";
	}
	return 0;
}