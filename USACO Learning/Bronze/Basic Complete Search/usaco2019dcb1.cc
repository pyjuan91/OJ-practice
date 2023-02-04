#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int k, n, x, res = 0;
	cin >> k >> n;
	vector<vector<int>> a(k, vector<int>(n + 1));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			a[i][x] = j;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bool checker = a[0][i] > a[0][j], yoJiea = true;
			for (int ii = 1; ii < k; ii++) {
				if (a[ii][i] > a[ii][j] != checker)
					yoJiea = false;
			}
			if (yoJiea) res += 1;
		}
	}
	cout << res;
	return 0;
}