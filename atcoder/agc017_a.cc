#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[55], n, p, dp[2][2] = {}, x;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> p >> x;
	p &= 1, x &= 1;
	dp[0][0] = 1, dp[0][1] = 0;
	dp[1][0] = x == 0, dp[1][1] = x == 1;
	for (int i = 1; i < n; i++) {
		dp[0][0] = dp[0][0] + dp[1][0];
		dp[0][1] = dp[0][1] + dp[1][1];
		cin >> x;
		if (x & 1) {
			dp[1][0] = dp[0][1];
			dp[1][1] = dp[0][0];
		}
		else {
			dp[1][0] = dp[0][0];
			dp[1][1] = dp[0][1];
		}
	}
	cout << dp[0][p] + dp[1][p];
	return 0;
}