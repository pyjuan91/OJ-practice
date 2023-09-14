#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int left = 0, right = 1e9;
		bool ok = true;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) {
			if (a[i - 1] < a[i])
				right = min(
				  right, (a[i] + a[i - 1]) / 2);
			else if (a[i - 1] > a[i])
				left = max(
				  left, (a[i] + a[i - 1]) / 2 + ((a[i] + a[i - 1]) % 2));
		}
		if (left <= right) cout << left << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}
