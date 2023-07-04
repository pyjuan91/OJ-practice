#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[505][505] = {};
void init() {
	for (int i = 1; i < 505; i++) {
		for (int j = i + 1; j < 505; j++) {
			dp[i][j] = INT64_MAX;
			for (int cut = 1; cut < j; cut++) {
				int lx = i, ly = cut, rx = i, ry = j - cut;
				if (lx > ly) swap(lx, ly);
				if (rx > ry) swap(rx, ry);
				dp[i][j] = min(dp[i][j], dp[lx][ly] + dp[rx][ry] + 1);
			}
			for (int cut = 1; cut < i; cut++) {
				int lx = cut, ly = j, rx = i - cut, ry = j;
				if (lx > ly) swap(lx, ly);
				if (rx > ry) swap(rx, ry);
				dp[i][j] = min(dp[i][j], dp[lx][ly] + dp[rx][ry] + 1);
			}
		}
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	init();
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	cout << dp[a][b];
	return 0;
}