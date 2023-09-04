#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(string& s) {
	int res = 0, n = s.length();
	s = " " + s;
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	for (int i = 1; i <= n; i++) {
		if (s[i] == '?') {
			dp[i][0] = dp[i - 1][1] + 1;
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else if (s[i] == '0') dp[i][0] = dp[i - 1][1] + 1;
		else dp[i][1] = dp[i - 1][0] + 1;
		res += max(dp[i][0], dp[i][1]);
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << chaewon(s) << '\n';
	}
	return 0;
}