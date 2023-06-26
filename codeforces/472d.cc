#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (auto &row : g)
		for (auto &x : row) cin >> x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][i] != 0 || g[i][j] != g[j][i] || i != j && g[i][j] == 0) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int mst_edge = 0;
		for (int j = 0; j < n; j++)
			if (j != i && g[i][mst_edge] > g[i][j])
				mst_edge = j;
		for (int j = 0; j < n; j++) {
			if (llabs(g[j][i] - g[j][mst_edge]) != g[i][mst_edge]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}