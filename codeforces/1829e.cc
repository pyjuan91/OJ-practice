#include <bits/stdc++.h>
#define int long long
using namespace std;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int chaewon(vector<vector<int>>& g, const int& n, const int& m, int cur_x, int cur_y) {
	int res = g[cur_x][cur_y];
	g[cur_x][cur_y] = 0;
	for (int i = 0; i < 4; i++) {
		auto nx = cur_x + dx[i];
		auto ny = cur_y + dy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny]) {
			res += chaewon(g, n, m, nx, ny);
		}
	}
	return res;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m, res = 0;
	cin >> t;
	while (t--) {
		res = 0;
		cin >> n >> m;
		vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> g[i][j];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] == 0) continue;
				res = max(res, chaewon(g, n, m, i, j));
			}
		}
		cout << res << "\n";
	}
	return 0;
}