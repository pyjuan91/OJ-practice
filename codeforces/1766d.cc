#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	const int N = 3200;
	vector<int> lp(N + 1);
	vector<int> pr;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) { break; }
		}
	}
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, diff;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a < b) swap(a, b);
		diff = a - b;
		if (diff == 1) {
			cout << "-1\n";
			continue;
		}
		if (gcd(a, b) != 1) {
			cout << "0\n";
			continue;
		}
		int res = INT32_MAX;
		for (auto p : pr) {
			if (p * p > diff) break;
			if (diff % p == 0) {
				res = min(res, p - a % p);
				while (diff % p == 0) diff /= p;
			}
		}
		if (diff > 1) res = min(res, diff - a % diff);
		cout << res << '\n';
	}
	return 0;
}
