#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k, x;
	map<int, int> m;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		while (n--) {
			cin >> x;
			m[x]++;
		}
		int left = -1, right = -1, prev = 0, res_l = -1, res_r = -2;
		for (auto& [x, y] : m) {
			if (y < k) {
				prev = 0;
				continue;
			}
			if (prev == 0) left = right = prev = x;
			else {
				right = x;
				if (x != prev + 1) left = x;
				prev = x;
			}
			if (right - left > res_r - res_l) {
				res_l = left;
				res_r = right;
			}
		}
		if (res_l == -1) cout << "-1\n";
		else cout << res_l << ' ' << res_r << '\n';
		m.clear();
	}
	return 0;
}
