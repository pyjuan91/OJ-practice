#include <bits/stdc++.h>
using namespace std;
void chaewon(vector<vector<bool>>& wall, vector<vector<bool>>& available, int n, int m) {
	if (available[n][m] || wall[n][m]) return;
	available[n][m] = true;
	chaewon(wall, available, n + 1, m);
	chaewon(wall, available, n - 1, m);
	chaewon(wall, available, n, m + 1);
	chaewon(wall, available, n, m - 1);
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<char>> g(n + 2, vector<char>(m + 2));
		vector<vector<bool>> wall(n + 2, vector<bool>(m + 2, false));
		for (int i = 0; i <= m + 1; i++)
			wall[0][i] = wall[n + 1][i] = true;
		for (int i = 0; i <= n + 1; i++)
			wall[i][0] = wall[i][m + 1] = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				cin >> g[i][j];
				if (g[i][j] == '#') wall[i][j] = true;
				else if (g[i][j] == 'B')
					wall[i][j] = wall[i + 1][j] = wall[i - 1][j]
					  = wall[i][j + 1] = wall[i][j - 1] = true;
			}
		vector<vector<bool>> available(n + 2, vector<bool>(m + 2, false));
		chaewon(wall, available, n, m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] == 'G' && !available[i][j]) {
					cout << "No\n";
					goto chaechae;
				}
			}
		}
		cout << "Yes\n";
	chaechae:;
	}
	return 0;
}