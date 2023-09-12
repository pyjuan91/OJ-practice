#include <bits/stdc++.h>
using namespace std;
int dp[1000000];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	for (int i = 0; i < 1000000; i++) dp[i] = 1e9;
	cin >> n >> m;
	dp[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int u = q.front(), step = dp[u];
		q.pop();
		if (u == m) {
			cout << dp[u] << '\n';
			return 0;
		}
		if (u - 1 > 0) {
			if (dp[u - 1] > step + 1) {
				dp[u - 1] = step + 1;
				q.push(u - 1);
			}
		}
		if (u * 2 < 1000000) {
			if (dp[u * 2] > step + 1) {
				dp[u * 2] = step + 1;
				q.push(u * 2);
			}
		}
	}
	return 0;
}
