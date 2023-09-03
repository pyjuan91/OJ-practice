#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> greatest_not_pair(n + 1, 0);
		while (m--) {
			cin >> a >> b;
			if (a > b) swap(a, b);
			greatest_not_pair[b] = max(greatest_not_pair[b], a);
		}
		int bound = -1, res = 0;
		for (int i = 1; i <= n; i++) {
			bound = max(bound, greatest_not_pair[i]);
			res += i - bound;
		}
		cout << res << '\n';
	}
	return 0;
}
