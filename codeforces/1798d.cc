#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> pos, neg, res;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x == 0) res.emplace_back(x);
			else if (x > 0) pos.emplace_back(x);
			else neg.emplace_back(x);
		}
		if ((int)res.size() == n) {
			cout << "NO\n";
			continue;
		}
		int prefix_sum = 0;
		while ((int)res.size() < n) {
			if (prefix_sum >= 0) {
				res.emplace_back(neg.back());
				prefix_sum += neg.back();
				neg.pop_back();
			}
			else {
				res.emplace_back(pos.back());
				prefix_sum += pos.back();
				pos.pop_back();
			}
		}
		cout << "YES\n";
		for (auto x : res) cout << x << " ";
		cout << "\n";
	}
	return 0;
}