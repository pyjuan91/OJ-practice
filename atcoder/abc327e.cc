#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
const double c = 0.9;
int n;
double dp[maxn][maxn], p[maxn], ans = -1e18, denu = 1.0;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i], dp[i][1] = p[i];

	for (int i = 2; i <= n; i++) {
		dp[i][i] = c * dp[i - 1][i - 1] + p[i];
		for (int j = i - 1; j >= 1; j--) {
			dp[i][j] = max(dp[i - 1][j], c * dp[i - 1][j - 1] + p[i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i] / denu - 1200.0 / sqrt(i));
		denu = denu * c + 1.0;
	}
	cout << setprecision(20) << ans << '\n';
	return 0;
}