#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<pair<int, int>> dp(1 << n, {n + 1, 0});
	for (auto &x : a) cin >> x;
	dp[0] = {1, 0};
	for (int cond = 1; cond < (1 << n); cond++) {
		for (int i = 0; i < n; i++) {
			if (cond & (1 << i)) {
				auto child = dp[cond ^ (1 << i)];
				if (child.second + a[i] <= x)
					child.second += a[i];
				else child.first += 1, child.second = a[i];
				dp[cond] = min(dp[cond], child);
			}
		}
	}
	cout << dp[(1 << n) - 1].first;
	return 0;
}