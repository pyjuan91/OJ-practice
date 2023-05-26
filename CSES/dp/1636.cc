#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> dp(x + 1, 0);
	for (auto& x : a) cin >> x;
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= x; j++) {
			if (j - a[i] >= 0) {
				dp[j] += dp[j - a[i]];
				dp[j] %= mod;
			}
		}
	}
	cout << dp[x] << "\n";
	return 0;
}