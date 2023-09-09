#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, q, x, l, r, a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> l >> r >> a >> b;
			v[i] = {l, b};
		}
		sort(v.begin(), v.end());
		vector<pair<int, int>> merged_v;
		pair<int, int> cur = v[0];
		for (auto p : v) {
			if (p.first > cur.second)
				merged_v.push_back(cur), cur = p;
			else cur.second = max(cur.second, p.second);
		}
		merged_v.push_back(cur);
		cin >> q;
		while (q--) {
			cin >> x;
			auto it = upper_bound(
			  merged_v.begin(), merged_v.end(), make_pair(x, INT32_MAX));
			if (it == merged_v.begin()) cout << x << " ";
			else {
				it--;
				cout << max(x, it->second) << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}
