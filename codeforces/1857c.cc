#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	map<int, int> m;
	cin >> t;
	while (t--) {
		m.clear();
		cin >> n;
		if (n == 2) {
			cin >> x;
			cout << x << ' ' << x << '\n';
			continue;
		}
		for (int i = 0; i < n * (n - 1) / 2; i++) {
			cin >> x;
			m[x]++;
		}

		vector<int> ans;
		n--;
		for (auto [k, v] : m) {
			while (v > 0 && v >= n) {
				ans.push_back(k);
				v -= n--;
			}
		}
		for (auto& x : ans) cout << x << ' ';
		cout << "1000000000\n";
	}
	return 0;
}
