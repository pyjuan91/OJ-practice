#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");

	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> g(n);
	for (auto& x : g) cin >> x;
	pair<int, int> max_area_min_perimeter = {0, 0};
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
	auto invalid = [&](int i, int j) {
		return i < 0 || i >= n || j < 0 || j >= n || g[i][j] == '.';
	};
	auto contribute_edge = [&](int x, int y) {
		int res = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (invalid(nx, ny)) res++;
		}
		return res;
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] == '.' || vis[i][j]) continue;
			vis[i][j] = true;
			queue<pair<int, int>> q;
			int area = 0, perimeter = 0;
			q.push({i, j});
			while (!q.empty()) {
				auto [x, y] = q.front();
				q.pop();
				area++;
				perimeter += contribute_edge(x, y);
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (invalid(nx, ny) || vis[nx][ny])
						continue;
					vis[nx][ny] = true;
					q.push({nx, ny});
				}
			}
			if (area > max_area_min_perimeter.first)
				max_area_min_perimeter = {area, perimeter};
			else if (area == max_area_min_perimeter.first)
				max_area_min_perimeter.second
				  = min(max_area_min_perimeter.second, perimeter);
		}
	}
	cout << max_area_min_perimeter.first << ' '
		 << max_area_min_perimeter.second << '\n';
	return 0;
}
