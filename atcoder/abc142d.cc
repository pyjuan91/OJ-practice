#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	const int N = 1000000;
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
	int a, b;
	cin >> a >> b;
	int g = __gcd(a, b);
	vector<int> res;
	for (auto x : pr) {
		if (g == 1) break;
		if (g % x == 0) {
			res.push_back(x);
			while (g % x == 0) g /= x;
		}
	}
	if (g > 1) res.push_back(g);
	cout << res.size() + 1 << '\n';
	return 0;
}
