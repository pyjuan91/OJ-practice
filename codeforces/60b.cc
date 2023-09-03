#include <bits/stdc++.h>
using namespace std;
char grid[11][11][11];
bool vis[11][11][11] = {};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int k, n, m, res = 0, x, y;
	cin >> k >> n >> m;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++) cin >> grid[i][j][l];
	}
	function<void(int, int, int)> dfs = [&](int i, int j, int l) {
		if (i < 0 || i >= k || j < 0 || j >= n || l < 0 || l >= m || vis[i][j][l] || grid[i][j][l] == '#')
			return;
		vis[i][j][l] = true;
		res++;
		dfs(i + 1, j, l);
		dfs(i - 1, j, l);
		dfs(i, j + 1, l);
		dfs(i, j - 1, l);
		dfs(i, j, l + 1);
		dfs(i, j, l - 1);
	};
	cin >> x >> y;
	dfs(0, x - 1, y - 1);
	cout << res << '\n';
	return 0;
}
