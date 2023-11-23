#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	auto is_prime = [&](int x) {
		if (x < 2) return 0;
		for (int i = 2; i * i <= x; i++)
			if (x % i == 0) return 0;
		return 1;
	};
	int n, q, op, l, r;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] = is_prime(a[i]);
	cin >> q;
	while (q--) {
		cin >> op >> l >> r;
		if (op == 1) {
			int res = 0;
			for (int i = l; i <= r; i++) res += a[i];
			cout << res << '\n';
		}
		else a[l] = is_prime(r);
	}
	return 0;
}
