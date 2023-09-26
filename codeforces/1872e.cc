#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int t, n, q, op, l, r, seg[maxn * 2], m0, m1;
string s;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i <= 2 * n + 5; i++) seg[i] = 0;
		m0 = m1 = 0;
		for (int i = 0; i < n; i++) cin >> seg[n + i];
		// build tree
		for (int i = n - 1; i > 0; i--)
			seg[i] = seg[i << 1] ^ seg[i << 1 | 1];
		cin >> s >> q;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') m0 ^= seg[n + i];
			else m1 ^= seg[n + i];
		}
		while (q--) {
			cin >> op;
			if (op == 1) {
				cin >> l >> r;
				int query = 0;
				for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
					if (l & 1) query ^= seg[l++];
					if (r & 1) query ^= seg[--r];
				}
				m0 ^= query;
				m1 ^= query;
			}
			else {
				cin >> r;
				if (r == 0) cout << m0 << " ";
				else cout << m1 << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
