#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, x, y, zero_row = -1;
int dp[maxn][maxn][2];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			y = x;
			if (x == 0) {
				dp[i][j][0] = dp[i][j][1] = 20000;
				zero_row = i;
				continue;
			}
			while (x % 2 == 0) x /= 2, dp[i][j][0]++;
			while (y % 5 == 0) y /= 5, dp[i][j][1]++;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (i == n - 1 && j == n - 1) continue;
			if (i == n - 1)
				dp[i][j][0] += dp[i][j + 1][0],
				  dp[i][j][1] += dp[i][j + 1][1];
			else if (j == n - 1)
				dp[i][j][0] += dp[i + 1][j][0],
				  dp[i][j][1] += dp[i + 1][j][1];
			else
				dp[i][j][0] += min(dp[i + 1][j][0], dp[i][j + 1][0]),
				  dp[i][j][1] += min(dp[i + 1][j][1], dp[i][j + 1][1]);
		}
	}
	// cannot bypass zero
	// 0 2      5 0
	// 5 0  or  0 2
	bool cond1 = (dp[0][0][0] >= 20000);
	// make greater than 1 zero
	bool cond2 = (dp[0][0][0] > 1 && dp[0][0][1] > 1 && zero_row != -1);
	if (cond1 || cond2) {
		cout << "1\n";
		for (int i = 0; i < zero_row; i++) cout << "D";
		for (int i = 0; i < n - 1; i++) cout << "R";
		for (int i = zero_row; i < n - 1; i++) cout << "D";
		return 0;
	}
	int win = dp[0][0][0] < dp[0][0][1] ? 0 : 1;
	cout << dp[0][0][win] << '\n';
	x = y = 0;
	while (x != n - 1 || y != n - 1) {
		if (x == n - 1) cout << "R", y++;
		else if (y == n - 1) cout << "D", x++;
		else {
			if (dp[x + 1][y][win] < dp[x][y + 1][win])
				cout << "D", x++;
			else cout << "R", y++;
		}
	}
	return 0;
}