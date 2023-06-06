#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	vector<int> in_degree(n + 1, 0), res;
	vector<vector<int>> route(n + 1);
	while (m--) {
		cin >> a >> b;
		route[a].emplace_back(b);
		in_degree[b] += 1;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (in_degree[i] == 0) q.push(i), res.emplace_back(i);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto child : route[cur]) {
			in_degree[child] -= 1;
			if (in_degree[child] == 0) {
				res.emplace_back(child);
				q.push(child);
			}
		}
	}
	if (res.size() == n)
		for (auto x : res) cout << x << " ";
	else cout << "IMPOSSIBLE\n";
	return 0;
}