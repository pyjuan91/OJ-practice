#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	int q, l, r, n;
	cin >> s >> q;
	n = s.length();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	vector<vector<bool>> is_palin(n, vector<bool>(n, false));
	for (int i = n - 1; i >= 0; i--) {
		is_palin[i][i] = true;
		dp[i][i] = 1;
		for (int j = i + 1; j < n; j++) {
			is_palin[i][j]
			  = ((s[i] == s[j]) && (j == i + 1 || is_palin[i + 1][j - 1]));
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1]
					 - dp[i + 1][j - 1] + is_palin[i][j];
		}
	}
	while (q--) {
		cin >> l >> r;
		cout << dp[--l][--r] << "\n";
	}
	return 0;
}