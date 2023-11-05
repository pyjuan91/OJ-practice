#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	vector<int> a(n + 1), in_degree(n + 1), g(n + 1), posi, nega;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
		if (g[i] != -1) in_degree[g[i]]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		res += a[u];
		if (a[u] >= 0) posi.emplace_back(u);
		else nega.emplace_back(u);
		if (g[u] != -1) {
			a[g[u]] += max(0ll, a[u]);
			in_degree[g[u]]--;
			if (in_degree[g[u]] == 0) q.push(g[u]);
		}
	}
	cout << res << '\n';
	for (auto iter = posi.begin(); iter != posi.end(); iter++)
		cout << *iter << ' ';
	for (auto iter = nega.rbegin(); iter != nega.rend(); iter++)
		cout << *iter << ' ';
	return 0;
}
