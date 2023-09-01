#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int sz = 0, zero_pos = -1, all_ones = 0;
		bool ok = true;
		for (auto c : s) {
			if (c == '+') sz++;
			else if (c == '-') {
				sz--;
				if (sz < zero_pos) zero_pos = -1;
				all_ones = min(all_ones, sz);
			}
			else if (c == '1') {
				if (zero_pos != -1) {
					ok = false;
					break;
				}
				all_ones = sz;
			}
			else {
				if (sz < 2 || all_ones == sz) {
					ok = false;
					break;
				}
				if (zero_pos == -1) zero_pos = sz;
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
	return 0;
}