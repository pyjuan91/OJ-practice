#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k, d;
	cin >> t;
	while (t--) {
		cin >> n >> k >> d;
		vector<int> a(n + 1), b(k + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= k; i++) cin >> b[i];

		int test_cnt = min(2 * n + 1, d);
		int ans = 0, idx = 1;
		for (int to_zero = 1; to_zero <= test_cnt; to_zero++) {
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == i) cur++;
			}
			cur += (d - to_zero) / 2;
			ans = max(ans, cur);
			for (int i = 1; i <= b[idx]; i++) a[i]++;
			idx++;
			if (idx > k) idx = 1;
		}
        cout << ans << '\n';
	}
	return 0;
}
