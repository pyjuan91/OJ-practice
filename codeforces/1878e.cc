#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int t, n, seg[2 * maxn], q, l, k;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i <= 2 * n + 5; i++) seg[i] = 0;
		for (int i = 0; i < n; i++) cin >> seg[i + n];
		for (int i = n - 1; i > 0; --i)
			seg[i] = seg[i << 1] & seg[i << 1 | 1];
		auto query = [&](int l, int r) {
			int res = seg[l + n];
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l & 1) res &= seg[l++];
				if (r & 1) res &= seg[--r];
			}
			return res;
		};
		cin >> q;
		while (q--) {
			cin >> l >> k;
			l--;
			if (seg[l + n] < k) {
				cout << "-1 ";
				continue;
			}
			int left = l, right = n - 1, mid, ans = left;
			while (left <= right) {
				mid = (left + right) / 2;
				if (query(l, mid + 1) < k) right = mid - 1;
				else ans = mid, left = mid + 1;
			}
            cout << ans + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}
