#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[505];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; i++) ans += abs(a[i] - a[n / 2]);
        cout << ans << '\n';
	}
	return 0;
}
