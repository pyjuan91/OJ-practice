#include <bits/stdc++.h>
using namespace std;
int left_zero[200005], right_one[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, l, r;
	string s;
	set<pair<int, int>> res;
	cin >> t;
	while (t--) {
		cin >> n >> m >> s;
		res.clear();
		left_zero[0] = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '0') left_zero[i] = i;
			else left_zero[i] = left_zero[i - 1];
		}
		right_one[n + 1] = n + 1;
		for (int i = n; i >= 1; i--) {
			if (s[i - 1] == '1') right_one[i] = i;
			else right_one[i] = right_one[i + 1];
		}
		while (m--) {
			cin >> l >> r;
			l = right_one[l];
			r = left_zero[r];
			if (l <= r) res.insert({l, r});
			else res.insert({-1, -1});
		}
		cout << res.size() << '\n';
	}
	return 0;
}
