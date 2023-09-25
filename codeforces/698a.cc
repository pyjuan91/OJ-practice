#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a[105], dp[105][3] = {};
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1 || a[i] == 3)
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][2]}) + 1;
		if (a[i] == 2 || a[i] == 3)
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1]}) + 1;
		dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
	}
	cout << n - max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
	return 0;
}
