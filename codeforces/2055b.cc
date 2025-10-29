#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) {
			cin >> x;
		}
		for (auto& x : b) {
			cin >> x;
		}

		int st = 0, eq = 0, gt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				st++;
			} else if (a[i] == b[i]) {
				eq++;
			} else {
				gt++;
			}
		}

		if (st > 1) {
			cout << "NO\n";
		} else if (st == 0) {
			cout << "YES\n";
		} else {
			int target = 0;
			vector<int> diffs;
			for (int i = 0; i < n; i++) {
				if (a[i] < b[i]) {
					target = b[i] - a[i];
				} else {
					diffs.push_back(a[i] - b[i]);
				}
			}
			if (target <= *min_element(diffs.begin(), diffs.end())) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
