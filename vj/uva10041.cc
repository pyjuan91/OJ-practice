#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[505], tar, ans;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		tar = (n % 2 ? a[n / 2] : (a[n / 2] + a[n / 2 - 1]) / 2);
		ans = 0;
		for (int i = 0; i < n; i++) ans += llabs(a[i] - tar);
		cout << ans << '\n';
	}
	return 0;
}
