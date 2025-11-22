#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int k, int x) {
	vector<int> res;
	while (x != (1LL << k)) {
		if (x < (1LL << k)) {
			res.push_back(1);
			x *= 2;
		} else {
			res.push_back(2);
			int other = (1LL << (k + 1)) - x;
			x -= other;
		}
	}
	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto v : res) {
		cout << v << ' ';
	}
	cout << '\n';
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, k, x;
	cin >> t;
	while (t--) {
		cin >> k >> x;
		patty(k, x);
	}
	return 0;
}
