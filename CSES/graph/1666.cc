#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> route(n + 1);
	while (m--) {
		cin >> a >> b;
		route[a].emplace_back(b);
		route[b].emplace_back(a);
	}
	vector<bool> used(n + 1, false);
	vector<pair<int, int>> res;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = true;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (auto child : route[cur]) {
					if (!used[child]) {
						used[child] = true;
						q.push(child);
					}
				}
			}
			if (i > 1) res.emplace_back(make_pair(1, i));
		}
	}
	cout << res.size() << "\n";
	for (auto p : res)
		cout << p.first << " " << p.second << "\n";
	return 0;
}