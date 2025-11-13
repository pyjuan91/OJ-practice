#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	constexpr int kMod = 1e9 + 7;
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	vector dp(w + 1, vector(n, -1));
	for (int i = 0; i < n; i++) {
		dp[0][i] = 1;
	}
	auto patty = [&](this auto& self, int u, int i) -> int {
		debug(u, i);
		if (u == 0) {
			return 1;
		}
		if (i == n) {
			return 0;
		}
		if (dp[u][i] != -1) {
			return dp[u][i];
		}

		int res = 0;

		for (int x = 0; x <= u; x += a[i]) {
			res = (res + self(u - x, i + 1)) % kMod;
			// debug(j, x, res);
		}

		return dp[u][i] = res;
	};

	cout << patty(w, 0) << "\n";
	return 0;
}
