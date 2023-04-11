#include <bits/stdc++.h>
using namespace std;
int chaewon(int, int);
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int n, k, q, a, b;
	cin >> n >> k;
	vector<vector<int>> g(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			if (g[i][j] == 0) g[i][j] = 2e9;
		}
	for (int mid = 0; mid < n; mid++) {
		for (int start = 0; start < n; start++) {
			for (int end = 0; end < n; end++) {
				if (g[start][end] > g[start][mid] + g[mid][end])
					g[start][end] = g[start][mid] + g[mid][end];
			}
		}
	}

	cin >> q;
	while (q--) {
		cin >> a >> b;
		a = (a - 1) % n;
		b = (b - 1) % n;
		cout << (g[a][b] == 2e9 ? -1 : g[a][b]) << endl;
	}
	return 0;
}