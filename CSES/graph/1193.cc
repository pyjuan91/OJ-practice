#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
const char dir[4] = {'U', 'D', 'L', 'R'};
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n + 2, vector<char>(m + 2, '#'));
	vector<vector<int>> res(n + 1, vector<int>(m + 1, -1));
	pair<int, int> a_pos = {0, 0}, b_pos = {-1, -1};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'A') a_pos = make_pair(i, j);
		}
	queue<pair<int, int>> q;
	q.push(a_pos);
	g[a_pos.first][a_pos.second] = '#';
	while (!q.empty()) {
		auto cur_pos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			auto nx = cur_pos.first + dx[i],
				 ny = cur_pos.second + dy[i];
			if (g[nx][ny] != '#') {
				res[nx][ny] = i;
				if (g[nx][ny] == 'B') {
					b_pos = make_pair(nx, ny);
				}
				g[nx][ny] = '#';
				q.push(make_pair(nx, ny));
			}
		}
	}
	if (b_pos.first == -1) cout << "NO\n";
	else {
		vector<int> ans;
		while (res[b_pos.first][b_pos.second] != -1) {
			ans.emplace_back(res[b_pos.first][b_pos.second]);
			auto nx = b_pos.first - dx[res[b_pos.first][b_pos.second]];
			auto ny = b_pos.second - dy[res[b_pos.first][b_pos.second]];
			b_pos = make_pair(nx, ny);
		}
		cout << "YES\n" << ans.size() << "\n";
		while (!ans.empty()) {
			cout << dir[ans.back()];
			ans.pop_back();
		}
	}
	return 0;
}