#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<char>> g(n + 1, vector<char>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> g[i][j];
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j] == '*') dp[j] = 0;
			else if (j > 0) dp[j] += dp[j - 1];
			dp[j] %= mod;
		}
	}
	cout << dp[n];
	return 0;
}