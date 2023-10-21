#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, res = 0;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	vector<pair<int, int>> sensors;
	vector<vector<bool>> vist(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == '#') sensors.push_back({i, j});
		}
	}
	const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	for (auto p : sensors) {
		if (vist[p.first][p.second]) continue;
		res++;
		vist[p.first][p.second] = true;
		queue<pair<int, int>> q;
		q.push(p);
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (vist[nx][ny] || v[nx][ny] == '.') continue;
				vist[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
    cout << res << '\n';
	return 0;
}
