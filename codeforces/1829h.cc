#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k, x;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> prev_dp(64, 0);
		for (int i = 0; i < n; i++) {
			vector<int> cur_dp(64, 0);
			cin >> x;
			cur_dp[x] = 1;
			for (int j = 0; j < 64; j++) {
				cur_dp[j] += prev_dp[j];
				cur_dp[j] %= mod;
				cur_dp[j & x] += prev_dp[j];
				cur_dp[j & x] %= mod;
			}
			swap(prev_dp, cur_dp);
		}
		int res = 0;
		for (int j = 0; j < 64; j++) {
			if (__builtin_popcount(j) == k)
				res += prev_dp[j], res %= mod;
		}
		cout << res << "\n";
	}
	return 0;
}