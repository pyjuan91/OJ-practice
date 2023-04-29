#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n, vector<char>(m));
	vector<int> res(min(n, m) + 1, 0);
	for (auto& row : g)
		for (auto& c : row) cin >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '#') {
				for (int edge = 1; edge < min(n, m); edge++) {
					bool bound_check
					  = (i + edge >= n || i - edge < 0 || j + edge >= m || j - edge < 0);
					if (bound_check) {
						res[edge - 1] += 1;
						break;
					}
					bool hash_check
					  = (g[i + edge][j + edge] != '#' || g[i + edge][j - edge] != '#' || g[i - edge][j + edge] != '#' || g[i - edge][j - edge] != '#');
					if (hash_check) {
						res[edge - 1] += 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i < min(n, m); i++) cout << res[i] << " ";
	cout << res[min(n, m)];
	return 0;
}