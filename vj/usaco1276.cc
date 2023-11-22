#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(3)), b(m, vector<int>(4));
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i][0] >> b[i][1] >> b[i][2] >> b[i][3];
	}
	int res = INT32_MAX;
	for (int mask = 0; mask < (1 << m); mask++) {
		int stalls[101] = {};
		int cost = 0;
		for (int i = 0; i < m; i++) {
			if (mask & (1 << i)) {
				for (int j = b[i][0]; j <= b[i][1]; j++)
					stalls[j] += b[i][2];
				cost += b[i][3];
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = a[i][0]; j <= a[i][1]; j++)
				if (stalls[j] < a[i][2]) ok = false;
		}
		if (ok) res = min(res, cost);
	}
    cout << res << '\n';
	return 0;
}
