#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, u, v;
	cin >> n;
	vector<vector<int>> route(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		route[u].emplace_back(v);
		route[v].emplace_back(u);
	}
	unordered_set<int> bir[2];
	vector<bool> used(n + 1, false);

	used[1] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	bir[0].insert(1);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto child : route[cur.first]) {
			if (!used[child]) {
				used[child] = true;
				bir[1 - cur.second].insert(child);
				q.push(make_pair(child, 1 - cur.second));
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (bir[0].find(i) != bir[0].end()) {
			int connected = 0;
			for (auto child : route[i]) {
				if (bir[1].find(child) != bir[1].end())
					connected += 1;
			}
			res += bir[1].size() - connected;
		}
	}
	cout << res;
	return 0;
}