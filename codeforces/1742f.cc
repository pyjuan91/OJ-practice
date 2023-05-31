#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, q, op, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> q;
		bool a_contains_others = false;
		bool b_contains_others = false;
		int a_counts = 1;
		int b_counts = 1;
		while (q--) {
			cin >> op >> k >> s;
			if (op == 1) {
				for (auto c : s) {
					if (c == 'a') a_counts += k;
					else a_contains_others = true;
				}
			}
			else {
				for (auto c : s) {
					if (c == 'a') b_counts += k;
					else b_contains_others = true;
				}
			}
			if (b_contains_others) cout << "YES\n";
			else if (a_contains_others || a_counts >= b_counts)
				cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}