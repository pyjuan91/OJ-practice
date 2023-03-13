#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[j - 1] == t[i - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j]
				  = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	int i = m - 1;
	int j = n - 1;
	string res = "";
	while (i >= 0 && j >= 0) {
		if (t[i] == s[j]) {
			res.push_back(t[i]);
			i -= 1;
			j -= 1;
		}
		else if (dp[i + 1][j + 1] > dp[i][j + 1])
			j -= 1;
		else i -= 1;
	}
    reverse(res.begin(), res.end());
    cout << res;
	return 0;
}