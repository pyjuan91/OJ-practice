#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, l, r, x, su;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		su = 0;
		while (m--) {
			cin >> l >> r >> x;
			su |= x;
		}
		auto fast_power = [&](int a, int b) {
			int res = 1;
			while (b) {
				if (b & 1) res = res * a % mod;
				a = a * a % mod;
				b >>= 1;
			}
			return res;
		};
		cout << fast_power(2, n - 1) * su % mod << '\n';
	}
	return 0;
}
