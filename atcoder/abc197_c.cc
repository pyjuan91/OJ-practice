#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	// cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = INT64_MAX;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	for (int cond = 0; cond < (1 << n); cond++) {
		int or_res = 0, xor_res = 0;
		for (int i = 0; i < n; i++) {
			or_res |= a[i];
			if (1 << i & cond) xor_res ^= or_res, or_res = 0;
		}
		res = min(res, xor_res ^ or_res);
	}
	cout << res << "\n";
	return 0;
}