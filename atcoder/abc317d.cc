#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, y, z, z_sum = 0, wins = 0, tar, res = INT32_MAX;
	cin >> n;
	vector<pair<int, int>> loses;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		z_sum += z;
		if (x > y) wins += z;
		else loses.push_back({(x + y + 1) / 2 - x, z});
	}
	if (wins > z_sum / 2) {
		cout << 0 << '\n';
		return 0;
	}
	tar = z_sum / 2 + 1 - wins;
	vector<int> dp(tar + 1, INT64_MAX);
	dp[0] = 0;
	for (auto& [x, y] : loses) {
		for (int i = tar; i >= 0; i--) {
			int j = min(i + y, tar);
			if (dp[i] != INT64_MAX)
				dp[j] = min(dp[j], dp[i] + x);
		}
	}
	cout << dp[tar] << '\n';
	return 0;
}
