#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, q;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.rbegin(), a.rend());
		for (int i = 1; i < n; i++) a[i] += a[i - 1];
		while (m--) {
			cin >> q;
			auto iter = lower_bound(a.begin(), a.end(), q);
			if (iter == a.end()) cout << -1 << '\n';
			else cout << iter - a.begin() + 1 << '\n';
		}
	}
	return 0;
}
