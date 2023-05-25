#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	int n, m;
	char c;
	cin >> n >> m;
	vector<vector<bool>> g(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '.') g[i][j] = true;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j]) {
				res += 1;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				g[i][j] = false;
				while (!q.empty()) {
					auto current = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = current.first + dx[i];
						int ny = current.second + dy[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny]) {
							g[nx][ny] = false;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	cout << res;
	return 0;
}