#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> a(n), dp(x + 5, 0);
	dp[0] = 1;
	for (auto& x : a) cin >> x;
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0)
				dp[i] = (dp[i] + dp[i - a[j]]) % mod;
		}
	}
	cout << dp[x] << "\n";
	return 0;
}