#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][i] = a[i];
	}
	// dp[i][j] == if seq[i..j] can produce best answer
	for (int len = 1; len < n; len++) {
		for (int i = 0, j = len; j < n; i++, j++) {
			dp[i][j] = a[i] - dp[i + 1][j];
			if (a[j] - dp[i][j - 1] > dp[i][j]) {
				dp[i][j] = a[j] - dp[i][j - 1];
			}
		}
	}
	cout << dp[0][n - 1];
	return 0;
}