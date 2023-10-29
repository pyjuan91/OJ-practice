#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int res = INT32_MAX, d, s;
		for (int i = 0; i < n; i++) {
			cin >> d >> s;
			res = min(res, d + (s - 1) / 2);
		}
		cout << res << '\n';
	}
	return 0;
}
