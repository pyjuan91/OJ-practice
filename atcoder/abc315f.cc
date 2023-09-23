#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
int n, x[maxn], y[maxn];
double dp[maxn][60];
double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int penalty(int skip_cnt) {
	if (skip_cnt == 0) return 0ll;
	return 1ll << (skip_cnt - 1);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 60; j++) dp[i][j] = 1e18;
	dp[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		// i is the current consideration
		for (int j = max(1ll, i - 60); j < i; j++) {
			// j is the previous consideration
			int drop_cnt = i - j - 1;
			for (int k = 0; k + drop_cnt < 60 && k < j; k++) {
				// k is the number of previous skip
				dp[i][k + drop_cnt] = min(
				  dp[i][k + drop_cnt],
				  dp[j][k] + dist(x[i], y[i], x[j], y[j])
					+ penalty(k + drop_cnt) - penalty(k));
			}
		}
	}
	double ans = 1e18;
	for (int drop_cnt = 0; drop_cnt < 60; drop_cnt++)
		ans = min(ans, dp[n][drop_cnt]);
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
