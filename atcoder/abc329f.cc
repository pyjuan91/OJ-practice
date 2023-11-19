#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x, a, b;
	cin >> n >> m;
	vector<set<int>> c(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		c[i].insert(x);
	}
	while (m--) {
		cin >> a >> b;
		if (c[a].size() > c[b].size()) swap(c[a], c[b]);
		for (auto x : c[a]) c[b].insert(x);
		c[a].clear();
		cout << c[b].size() << '\n';
	}
	return 0;
}
