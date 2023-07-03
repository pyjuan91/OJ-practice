#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n), lbc(n, INT64_MIN), rbc(n, INT64_MIN);
		int res = INT64_MIN;
		for (auto& x : a) cin >> x;
		for (int i = 0; i < n; i++)
			lbc[i] = max(a[i] + i, lbc[i ? i - 1 : 0]);
		for (int i = n - 1; i >= 0; i--)
			rbc[i] = max(a[i] - i, rbc[i == n - 1 ? i : i + 1]);
		for (int i = 1; i < n - 1; i++)
			res = max(res, a[i] + lbc[i - 1] + rbc[i + 1]);
		cout << res << "\n";
	}
	return 0;
}