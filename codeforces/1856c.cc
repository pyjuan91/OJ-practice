#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	auto check = [&](int guess_ma) {
		int res = INT64_MAX;
		for (int reach_on = 0; reach_on < n; reach_on++) {
			int need_step = 0;
			bool ok = true;
			for (int i = reach_on; i < n; i++) {
				int ideal = guess_ma - (i - reach_on);
				if (i != n - 1) {
					if (a[i] < ideal) need_step += ideal - a[i];
					else break;
				}
				else {
					if (a[i] < ideal) ok = false;
				}
			}
			if (ok) res = min(res, need_step);
		}
		return res;
	};
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		int left = *max_element(a, a + n), right = left + m + 1;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			if (check(mid) <= m) left = mid;
			else right = mid;
		}
		cout << left << "\n";
	}
	return 0;
}
