#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int t, n, res;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<vector<int>> dp(n, vector<int>(8));
		// 0 -> last flip end, this doesn't flip
		dp[1][0] = a[0] + a[1];
		// 1 -> last doesn't flip, this doesn't flip
		dp[1][1] = a[0] + a[1];
		// 2 -> last flip start , this flip end
		dp[1][2] = -a[0] - a[1];
		// 3 -> last doesn't flip, this flip start
		dp[1][3] = a[0] - a[1];
		// 4 -> last flip end, this flip start
		dp[1][4] = a[0] - a[1];
		// 5 -> last flip start, this doesn't flip(cont)
		dp[1][5] = -a[0] + a[1];
		// 6 -> last doens't flip(cont), this flip end
		dp[1][6] = -a[0] + -a[1];
		// 7 -> last doesn't flip (cont), this doensn't flip(const)
		dp[1][7] = -a[0] + a[1];
		for (int i = 2; i < n; i++) {
			dp[i][0] = a[i] + max(dp[i - 1][2], dp[i - 1][6]);
			dp[i][1] = a[i] + max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][2] = -a[i] + max(dp[i - 1][3], dp[i - 1][4]);
			dp[i][3] = -a[i] + max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][4] = -a[i] + max(dp[i - 1][2], dp[i - 1][6]);
			dp[i][5] = a[i] + max(dp[i - 1][3], dp[i - 1][4]);
			dp[i][6] = -a[i] + max(dp[i - 1][5], dp[i - 1][7]);
			dp[i][7] = a[i] + max(dp[i - 1][5], dp[i - 1][7]);
		}
		cout << max(
			{dp[n - 1][0], dp[n - 1][1], dp[n - 1][2],
			 dp[n - 1][6]})
				 << "\n";
	}
	return 0;
}