#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int> val(1001, INT32_MAX);
	val[1] = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			if (i + i / j <= 1000) {
				val[i + i / j] = min(val[i + i / j], val[i] + 1);
			}
		}
	}
	int t, n, k, su;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		su = 0;
		vector<int> b(n), c(n);
		for (auto& x : b) cin >> x;
		for (auto& x : c) cin >> x;
		for (int i = 0; i < n; i++)
			b[i] = val[b[i]], su += b[i];
		k = min(k, su);
		vector<int> dp(k + 1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = k - b[i]; j >= 0; j--)
				dp[j + b[i]] = max(dp[j + b[i]], dp[j] + c[i]);
		}
		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
	return 0;
}
