#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void chaewon(
	int n, int m, vector<vector<int>>& g,
	unordered_set<int>& s, int x, int y) {
	if (x == n - 1 && y == m - 1) {
		if (s.find(g[x][y]) == s.end()) ans += 1;
		return;
	}
	s.insert(g[x][y]);

	// right
	if (y + 1 < m && s.find(g[x][y + 1]) == s.end())
		chaewon(n, m, g, s, x, y + 1);
	// down
	if (x + 1 < n && s.find(g[x + 1][y]) == s.end())
		chaewon(n, m, g, s, x + 1, y);
	s.erase(g[x][y]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> grid[i][j];
	unordered_set<int> s;
    chaewon(n, m, grid, s, 0, 0);
    cout << ans;
	return 0;
}