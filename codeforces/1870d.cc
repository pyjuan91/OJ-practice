#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (auto& x : a) cin >> x;
		cin >> k;
		for (int i = n - 1; i > 0; i--) {
			a[i - 1] = min(a[i - 1], a[i]);
			a[i] -= a[i - 1];
		}
		int reach = INT32_MAX;
		for (int i = 0; i < n; i++) {
			if (a[i]) reach = min(reach, k / a[i]);
			k -= a[i] * reach;
			cout << reach << " \n"[i == n - 1];
		}
	}
	return 0;
}
