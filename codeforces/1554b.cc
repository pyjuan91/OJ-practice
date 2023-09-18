#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int res = INT32_MIN;
		for (int j = 2; j <= n; j++)
			for (int i = max(1ll, n - 2 * k - 1); i < j; i++)
				res = max(res, i * j - k * (a[i] | a[j]));
		cout << res << '\n';
	}
	return 0;
}
