#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, a, b, res = 0;
	cin >> n;
	vector<vector<int>> e(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		e[a].emplace_back(b);
		e[b].emplace_back(a);
	}
	for (auto i : e) res = max(res, (int) i.size());
	cout << res + 1;
	return 0;
}