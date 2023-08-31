#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (k <= n) {
			int window = 0, res = 0;
			for (int i = 1; i <= k; i++) window += a[i];
			res = max(res, window);
			for (int i = k + 1; i <= n; i++) {
				window += a[i] - a[i - k];
				res = max(res, window);
			}
			cout << res + k * (k - 1) / 2 << '\n';
		}
		else {
			int res = 0, one_round = 0;
			for (int i = 1; i <= n; i++) res += a[i];
			cout << k * n - n * (n + 1) / 2 + res << '\n';
		}
	}
	return 0;
}
