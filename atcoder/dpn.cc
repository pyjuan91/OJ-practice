#include <bits/stdc++.h>
using namespace std;
int main() {
#define int long long
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<int> a(n + 1), prefix(n + 1, 0);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prefix[i] = a[i] + prefix[i - 1];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1, j = len; j <= n; i++, j++) {
			dp[i][j] = dp[i][i] + dp[i + 1][j];
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			dp[i][j] += prefix[j] - prefix[i - 1];
		}
	}
	cout << dp[1][n];
	return 0;
}