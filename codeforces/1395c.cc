#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, res = INT32_MAX;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	for (int A = 0; A < (1 << 9); A++) {
		bool ok = true;
		for (auto x : a) {
			bool pass = false;
			for (auto y : b) {
				if (((x & y) | A) == A) {
					pass = true;
					break;
				}
			}
			if (!pass) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << A << '\n';
			return 0;
		}
	}
	return 0;
}
