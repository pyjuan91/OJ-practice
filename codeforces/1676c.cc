#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int res = INT32_MAX;
		auto diff = [&](const string& a, const string& b) {
			int res = 0;
			for (int i = 0; i < m; i++) {
				res += abs(a[i] - b[i]);
			}
			return res;
		};
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				res = min(res, diff(a[i], a[j]));
		}
		cout << res << '\n';
	}
	return 0;
}
