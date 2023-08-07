#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	while (cin >> n) {
		vector<pair<int, int>> ans;
		for (int i = n + 1; i <= 2 * n; i++) {
			if ((n * i) % (i - n) == 0) {
				ans.push_back({(n * i) / (i - n), i});
			}
		}
		cout << ans.size() << '\n';
		for (auto p : ans) {
			cout << "1/" << n << " = 1/" << p.first << " + 1/"
				 << p.second << '\n';
		}
	}
	return 0;
}
