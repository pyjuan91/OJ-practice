#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n), diff;
		for (auto &x : a) cin >> x;
		n -= 1;
		vector<int> seg(2 * n + 50, 0);
		auto build = [&]() {
			for (int i = n - 1; i > 0; i--)
				seg[i] = gcd(seg[i << 1], seg[i << 1 | 1]);
		};
		auto query = [&](int l, int r) {
			int res = 0;
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l & 1) res = gcd(res, seg[l++]);
				if (r & 1) res = gcd(res, seg[--r]);
			}
			return res;
		};
		bool space = false;
		for (int i = 0; i < n; i++) {
			seg[i + n] = llabs(a[i] - a[i + 1]);
			if (seg[i + n] != 1) space = true;
		}
		if (!space) {
			cout << 1 << '\n';
			continue;
		}
		build();
		int start = 0, res = 0;
		for (int end = 0; end < n; end++) {
			while (start < end && query(start, end + 1) == 1)
				start++;
			res = max(res, end - start + 1);
		}
		cout << res + 1 << '\n';
	}
	return 0;
}
