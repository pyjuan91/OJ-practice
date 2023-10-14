#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, g[205][205];
double x[205], y[205], p[205];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> p[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = ceil((abs(x[i] - x[j]) + abs(y[i] - y[j])) / p[i]);
		}
	}
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				g[start][end] = min(
				  g[start][end], max(g[start][mid], g[mid][end]));
			}
		}
	}
	int res = INT64_MAX;
	for (int start = 1; start <= n; start++) {
		int mac = INT64_MIN;
		for (int end = 1; end <= n; end++) {
			mac = max(mac, g[start][end]);
		}
		res = min(res, mac);
	}
	cout << res << '\n';
	return 0;
}
