#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, a, b, res = 0;
	cin >> n >> m;
	vector<vector<int>> route(n + 1), dp(1 << n, vector<int>(n));
	while (m--) {
		cin >> a >> b;
		a--, b--;
		route[b].emplace_back(a);
	}
	dp[1][0] = 1;
	for (int flight_set = 2; flight_set < (1 << n); flight_set++) {
		if ((flight_set & 1) == 0) continue;
		if ((flight_set & (1 << (n - 1))) && flight_set != ((1 << n) - 1))
			continue;
		for (int end_city = 0; end_city < n; end_city++) {
			if ((flight_set & (1 << end_city)) == 0) continue;
			int prev_state = flight_set - (1 << end_city);
			for (int start_city : route[end_city]) {
				if ((flight_set & (1 << start_city)) == 0)
					continue;
				dp[flight_set][end_city] += dp[prev_state][start_city];
				dp[flight_set][end_city] %= mod;
			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1];
	return 0;
}