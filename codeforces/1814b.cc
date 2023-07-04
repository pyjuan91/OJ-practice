#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	double a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int res = INT64_MAX;
		for (int k = 1; k < 100005; k++)
			res = min(
			  res, int64_t(ceil(a / (1.0 * k)))
					 + int64_t(ceil(b / (1.0 * k))) + k - 1);
		cout << res << "\n";
	}
	return 0;
}