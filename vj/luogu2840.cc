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
	vector<int> dp(w + 1, -1);
	dp[0] = 1;

	auto patty = [&](this auto& self, int u) -> int {
		if (dp[u] != -1) {
			return dp[u];
		}
		int res = 0;
		for (const auto& x : a) {
			if (x <= u) {
				res = (res + self(u - x)) % kMod;
			}
		}
		return dp[u] = res;
	};

	cout << patty(w) << "\n";
	return 0;
}
