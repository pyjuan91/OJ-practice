#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int res = INT32_MAX, res_a, res_b, res_c;
		for (int guess_a = 1; guess_a <= min(2 * a, 10000); guess_a++) {
			// ideal_b = k1 * guess_a
			// ideal_c = k1 * k2 * guess_a
			for (int k1 = 1; k1 * guess_a <= 2e4; k1++) {
				for (int k2 = 1; k2 * k1 * guess_a <= 2e4; k2++) {
					int ideal_b = k1 * guess_a;
					int ideal_c = k1 * k2 * guess_a;
					int cost = abs(a - guess_a) + abs(b - ideal_b)
							 + abs(c - ideal_c);
					if (cost < res) {
						res = cost;
						res_a = guess_a;
						res_b = ideal_b;
						res_c = ideal_c;
					}
				}
			}
		}
		cout << res << '\n'
			 << res_a << ' ' << res_b << ' ' << res_c << '\n';
	}
	return 0;
}
