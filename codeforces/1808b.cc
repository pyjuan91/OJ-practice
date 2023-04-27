#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int t, n, m, x;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		vector<vector<int>> cards(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> x;
				cards[j].emplace_back(x);
			}
		}

		for (int i = 0; i < m; i++) {
			sort(cards[i].begin(), cards[i].end());
		}

		int res = 0;
		for (int i = 0; i < m; i++) {
			int mul = n - 1;
			while (!cards[i].empty()) {
				res += cards[i].back() * mul;
				cards[i].pop_back();
				mul -= 2;
			}
		}

		cout << res << "\n";
	}
	return 0;
}