#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
int a[maxn], dp[maxn][5][2], prema[maxn];
const int v[5] = {1, 10, 100, 1000, 10000};
int chaewon(auto n) {
	reverse(a, a + n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 2; k++) dp[i][j][k] = INT64_MIN;

	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 2; k++) {
				if (dp[i - 1][j][k] == INT64_MIN) continue;
				if (j > a[i - 1])
					dp[i][j][k] = max(
					  dp[i][j][k], dp[i - 1][j][k] - v[a[i - 1]]);
				else
					dp[i][a[i - 1]][k] = max(
					  dp[i][a[i - 1]][k], dp[i - 1][j][k] + v[a[i - 1]]);
			}

			for (int k = 0; k < 5; k++) {
				if (dp[i - 1][j][0] == INT64_MIN) continue;
				if (j > k)
					dp[i][j][1]
					  = max(dp[i][j][1], dp[i - 1][j][0] - v[k]);
				else
					dp[i][k][1]
					  = max(dp[i][k][1], dp[i - 1][j][0] + v[k]);
			}
		}
	}

	int res = INT64_MIN;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++) res = max(res, dp[n][i][j]);
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		n = s.length();
		for (int i = 0; i < n; i++) a[i] = s[i] - 'A';
		cout << chaewon(n) << "\n";
	}
	return 0;
}