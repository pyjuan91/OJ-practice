#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n == 1) {
			cout << max(0ll, a[1]) << "\n";
			continue;
		}
		int res = 0;
		if (a[1] >= 0) {
			for (int i = 3; i <= n; i++) {
				if (a[i] > 0) res += a[i];
			}
			cout << max(res + a[1], res + a[1] + a[2]) << "\n";
		}
		else {
			for (int i = 3; i <= n; i++) {
				if (a[i] > 0) res += a[i];
			}
			cout << max(res + a[1] + a[2], res) << "\n";
		}
	}
	return 0;
}
