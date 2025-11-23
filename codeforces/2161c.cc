#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		deque<int> a(n);
		for (auto& x : a) {
			cin >> x;
		}
		sort(a.begin(), a.end());
		int sum = 0, res_sum = 0;
		vector<int> res_seq;

		while (!a.empty()) {
			int org = sum / m;
			if ((sum + a.back()) / m > org) {
				sum += a.back();
				res_sum += a.back();
				res_seq.push_back(a.back());
				a.pop_back();
			} else {
				sum += a.front();
				res_seq.push_back(a.front());
				a.pop_front();
			}
		}

		cout << res_sum << "\n";
		for (const auto& x : res_seq) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
