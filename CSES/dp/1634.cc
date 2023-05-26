#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for (auto &x : c) cin >> x;
	vector<int> dp(x + 5, 2e9);
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - c[j] >= 0)
				dp[i] = min(dp[i], 1 + dp[i - c[j]]);
		}
	}
	cout << (dp[x] == 2e9 ? -1 : dp[x]) << "\n";
	return 0;
}