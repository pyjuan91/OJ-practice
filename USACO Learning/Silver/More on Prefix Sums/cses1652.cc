#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, x1, x2, y1, y2;
	char c;
	cin >> n >> q;
	vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == '*') a[i][j] = 1;
			a[i][j] += a[i - 1][j] + a[i][j - 1]
					 - a[i - 1][j - 1];
		}
	}
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << a[x2][y2] - a[x1 - 1][y2]
				  - a[x2][y1 - 1] + a[x1 - 1][y1 - 1]
			 << "\n";
	}
	return 0;
}