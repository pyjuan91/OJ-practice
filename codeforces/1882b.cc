#include <bits/stdc++.h>
int a[55][55], t, n, k, x;
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			memset(a[i], 0, sizeof(a[i]));
			cin >> k;
			while (k--) {
				cin >> x;
				a[i][x] = 1;
			}
		}
		int res = 0;
		for (int i = 1; i <= 50; i++) {
			// i is the possible skip
			vector<int> v;
			for (int j = 1; j <= n; j++) {
				if (!a[j][i]) v.emplace_back(j);
			}
			if (v.size() == n) continue;
			int cnt = 0;
			for (int j = 1; j <= 50; j++) {
				// j is the union
				for (auto x : v) {
					if (a[x][j]) {
						cnt++;
						break;
					}
				}
			}
			res = max(res, cnt);
		}
        cout << res << '\n';
	}
	return 0;
}
