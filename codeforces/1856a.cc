#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v(n), org(n);
		for (int i = 0; i < n; i++) {
			cin >> org[i];
			v[i] = org[i];
		}
		sort(v.begin(), v.end());
		int rb = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] != org[i]) {
				rb = i + 1;
				break;
			}
		}
		if (rb == 0) {
			cout << 0 << "\n";
			continue;
		}
		int res = INT32_MIN;
		for (int i = 0; i < rb; i++) res = max(res, org[i]);
		cout << res << "\n";
	}
	return 0;
}
