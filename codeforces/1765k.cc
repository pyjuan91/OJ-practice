#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, res = 0, current, mi = INT64_MAX;
	cin >> n;
	vector<vector<int>> g(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
			res += g[i][j];
			if (i + j == n + 1) mi = min(mi, g[i][j]);
		}
	res -= mi;
	cout << res << "\n";
}