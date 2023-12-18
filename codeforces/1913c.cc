#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, op, x, bits[30] = {};

	cin >> t;
	while (t--) {
		cin >> op >> x;
		if (op == 1) bits[x]++;
		else if (op == 2) {
			bool ok = true;
			int tmp[30] = {};
			for (int i = 0; i < 30; i++) tmp[i] = bits[i];
			for (int i = 0; i < 30; i++) {
				if (1 << i & x) {
					if (tmp[i] == 0) {
						ok = false;
						break;
					}
					else tmp[i]--;
				}
				if (tmp[i] > 1 && i < 29)
					tmp[i + 1] += tmp[i] / 2;
			}
			cout << (ok ? "YES\n" : "NO\n");
		}
	}
	return 0;
}
