#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k, q;
	cin >> t;
	while (t--) {
		cin >> n >> k >> q;
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		int index = 0, res = 0, consecutive_days = 0;
		for (;;) {
			if (index >= n) break;
			while (index < n && a[index] <= q) {
				consecutive_days += 1;
				index++;
			}
			if (consecutive_days >= k)
				res += (consecutive_days - k + 1)
					 * (consecutive_days - k + 2) / 2;
            consecutive_days = 0;
            index++;
		}
		cout << res << "\n";
	}
	return 0;
}