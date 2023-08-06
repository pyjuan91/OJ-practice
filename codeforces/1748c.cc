#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	map<int, int> m;
	while (t--) {
		cin >> n;
		vector<int> prefix(n + 1, 0), zero, a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			prefix[i] = prefix[i - 1] + a[i];
		}
		m.clear();
		int res = 0, ma = INT32_MIN;
		for (int i = n; i >= 1; i--) {
			m[prefix[i]]++;
			ma = max(ma, m[prefix[i]]);
			if (a[i] == 0) {
				res += ma;
				m.clear();
				ma = INT32_MIN;
			}
		}
        res += m[0];
        cout << res << '\n';
	}
	return 0;
}
