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
	int n, w;
	cin >> n >> w;
	vector<int> dp(w + 1, INT32_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int i = x; i <= w; i++) {
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}
	cout << dp[w] << "\n";
	return 0;
}
