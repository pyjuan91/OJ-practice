#include <bits/stdc++.h>
using namespace std;
int a[100001], dp[100001];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, res;
	cin >> t;
	while (t--) {
		cin >> n;
		res = INT32_MIN;
		for (int i = 1; i <= n; i++) cin >> a[i], dp[i] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 2 * i; j <= n; j += i) {
				if (a[i] < a[j]) dp[j] = max(dp[j], dp[i] + 1);
				res = max(res, dp[j]);
			}
		}
		cout << max(res, 1) << '\n';
	}
	return 0;
}
