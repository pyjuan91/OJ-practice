#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x1, x2;
	cin >> n >> m >> x1 >> x2;
	vector<string> dp(m + 1, "");
	dp[x1] = "H", dp[x2] = "T";
	for (int i = 1; i < n; i++) {
		cin >> x1 >> x2;
		for (int j = m; j >= 0; j--) {
			if (j - x1 >= 0 && dp[j - x1].length())
				dp[j] = dp[j - x1] + "H";
			else if (j - x2 >= 0 && dp[j - x2].length())
				dp[j] = dp[j - x2] + "T";
			else dp[j] = "";
		}
	}
	if (!dp[m].length()) cout << "No";
	else cout << "Yes\n" << dp[m];
	return 0;
}