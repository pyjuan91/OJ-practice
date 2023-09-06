#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, x, left, right;
	set<int> s;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		left = right = 0;
		s.clear();
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x == -1) left++;
			else if (x == -2) right++;
			else s.insert(x);
		}
		if (s.empty()) {
			cout << min(m, max(left, right)) << '\n';
			continue;
		}
		int su = 0, prev = 0, res = INT32_MIN, pref = 0, lm, rm;
		for (auto x : s) su += x - prev - 1, prev = x;
		su += m - prev;
		prev = 0;
		res = max(min(su, left), min(su, right));
		for (auto x : s) {
			pref += x - prev - 1;
			prev = x;
			lm = min(pref, left);
			rm = min(su - pref, right);
			res = max(res, lm + rm);
		}
		pref += m - prev;
		lm = min(pref, left);
		rm = min(su - pref, right);
		res = max(res, lm + rm);
		cout << res + s.size() << '\n';
	}
	return 0;
}
