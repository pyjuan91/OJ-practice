#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m;
	string s;
	cin >> n >> m;
	vector<int> dp(m, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '.') {
				if (j)
					dp[j] = (dp[j] + dp[j - 1]) % (int) (1e9 + 7);
			}
			else dp[j] = 0;
		}
	}
	cout << dp[m - 1];
	return 0;
}