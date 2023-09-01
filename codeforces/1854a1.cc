#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[25];
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> res;
		for (int i = 1; i <= n; i++) cin >> a[i];
		auto all_neg = [&]() {
			for (int i = 1; i <= n; i++)
				if (a[i] > 0) return false;
			return true;
		};
		if (all_neg()) {
			int mi, miid;
			mi = miid = INT32_MAX;
			for (int i = 1; i <= n; i++) {
				if (a[i] < mi) {
					mi = a[i];
					miid = i;
				}
			}
			res.emplace_back(n, miid);
			for (int i = n - 1; i >= 1; i--)
				res.emplace_back(i, i + 1);
		}
		else {
			int ma, maid;
			ma = maid = INT32_MIN;
			for (int i = 1; i <= n; i++) {
				if (a[i] > ma) {
					ma = a[i];
					maid = i;
				}
			}
			while (ma <= 20) {
				res.emplace_back(maid, maid);
				ma *= 2;
				a[maid] = ma;
			}
			for (int i = 2; i <= n; i++) {
				while (a[i] < a[i - 1]) {
					res.emplace_back(i, maid);
					a[i] += ma;
					if (a[i] > ma) {
						ma = a[i];
						maid = i;
					}
				}
			}
		}
		cout << res.size() << '\n';
		for (auto [x, y] : res) cout << x << ' ' << y << '\n';
	}
	return 0;
}
