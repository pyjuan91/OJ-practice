#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[101][101][2] = {};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, d, res = 0, mod = 1e9 + 7;
	cin >> n >> k >> d;
	for (int sel = 1; sel <= k; sel++) {
		if (sel >= d) dp[1][sel][1] = 1;
		else dp[1][sel][0] = 1;
	}
    res += dp[1][n][1];
	for (int layer = 2; layer <= n; layer++) {
		for (int su = 1; su <n; su++) {
			for (int sel = 1; sel <= k; sel++) {
				if (sel + su > n) break;
				if (sel < d) {
					dp[layer][su + sel][0] += dp[layer - 1][su][0];
					dp[layer][su + sel][0] %= mod;
					dp[layer][su + sel][1] += dp[layer - 1][su][1];
					dp[layer][su + sel][1] %= mod;
				}
				else {
					dp[layer][su + sel][1] += dp[layer - 1][su][0];
					dp[layer][su + sel][1] %= mod;
					dp[layer][su + sel][1] += dp[layer - 1][su][1];
					dp[layer][su + sel][1] %= mod;
				}
				// std::cout << layer << " " << su << " " << sel << " "
				// 	 << dp[layer][su+sel][0] << " "
				// 	 << dp[layer][su+sel][1] << '\n';
			}
		}
		res += dp[layer][n][1];
        res %= mod;
	}
	std::cout << res << '\n';
	return 0;
}
