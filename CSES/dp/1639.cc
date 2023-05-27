#include <bits/stdc++.h>
using namespace std;
int chaewon(string a, string b) {
	auto n = a.length(), m = b.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 2e9));
	for (int i = 0; i <= n; i++) dp[i][0] = i;
	for (int j = 0; j <= m; j++) dp[0][j] = j;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			}
			else {
				auto replace_this_char = dp[i - 1][j - 1] + 1;
				auto add_one_char = dp[i][j - 1] + 1;
				auto remove_one_char = dp[i - 1][j] + 1;
				dp[i][j]
				  = min({dp[i][j], replace_this_char, add_one_char, remove_one_char});
			}
		}
	}
	return dp[n][m];
}
int main() {
	cin.tie()->sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	cout << chaewon(a, b) << "\n";
	return 0;
}