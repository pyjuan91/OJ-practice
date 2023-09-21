#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, h, l, r, a[2005], dp[2005][2005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> h >> l >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++)
		for (int time = 0; time < h; time++) dp[i][time] = -1e9;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int time = 0; time < h; time++) {
			int t1 = (time + a[i]) % h;
			dp[i][t1] = max(
			  dp[i][t1], dp[i - 1][time] + (t1 >= l && t1 <= r));
			int t2 = (time + a[i] - 1) % h;
			dp[i][t2] = max(
			  dp[i][t2], dp[i - 1][time] + (t2 >= l && t2 <= r));
		}
	}
	cout << *max_element(dp[n], dp[n] + h) << '\n';
	return 0;
}
