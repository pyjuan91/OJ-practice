#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int dp[2030][2030], row[maxn], col[maxn];
void chaewon() {
	int cur = 1;
	for (int i = 1; i <= 2023 && cur < maxn; i++) {
		for (int j = 1; j <= i && cur < maxn; j++) {
			row[cur] = i;
			col[cur] = j;
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + cur * cur;
			if (i >= 3) dp[i][j] -= dp[i - 2][j - 1];
			cur += 1;
		}
	}
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	chaewon();
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[row[n]][col[n]] << "\n";
	}
	return 0;
}