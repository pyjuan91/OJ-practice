#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	const int dx[] = {0, 0, 1, -1};
	const int dy[] = {1, -1, 0, 0};
	int n, m, x1, y1, x2, y2;
	cin >> n >> m;
	auto valid = [&](int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> v[i][j];
	}
	cin >> x1 >> y1 >> x2 >> y2;
	x1--, y1--, x2--, y2--;
	if (x1 == x2 && y1 == y2) {
		for (int i = 0; i < 4; i++) {
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			if (valid(nx, ny) && v[nx][ny] == '.') {
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
		return 0;
	}
	function<bool(int, int)> dfs = [&](int x, int y) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == x2 && ny == y2) return true;
			if (valid(nx, ny) && v[nx][ny] == '.') {
				v[nx][ny] = 'X';
				if (dfs(nx, ny)) return true;
			}
		}
		return false;
	};
	auto route_cnt = [&](int x, int y) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (valid(nx, ny) && v[nx][ny] == '.') cnt++;
		}
		return cnt;
	};
	if (v[x2][y2] == 'X') {
		cout << (dfs(x1, y1) ? "YES\n" : "NO\n");
		return 0;
	}
	if (abs(x1 - x2) + abs(y1 - y2) == 1) {
		cout << (route_cnt(x2, y2) > 0 ? "YES\n" : "NO\n");
		return 0;
	}
	bool con1 = route_cnt(x2, y2) > 1;
	bool con2 = dfs(x1, y1);
	cout << (con1 && con2 ? "YES\n" : "NO\n");
	return 0;
}