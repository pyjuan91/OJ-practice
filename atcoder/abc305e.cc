#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k, a, b;
	cin >> n >> m >> k;
	vector<vector<int>> g(n + 1);
	set<int> res;
	while (m--) {
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	priority_queue<pair<int, int>> pq;
	vector<int> remain_energy(n + 1, -1);
	while (k--) {
		cin >> a >> b;
		pq.push(make_pair(b, a));
	}
	while (!pq.empty()) {
		auto [energy, node] = pq.top();
		pq.pop();
		if (remain_energy[node] < energy) {
			remain_energy[node] = energy;
			res.insert(node);
			for (auto& e : g[node]) {
				if (remain_energy[e] < energy - 1)
					pq.push(make_pair(energy - 1, e));
			}
		}
	}
	cout << res.size() << '\n';
	for (auto& e : res) cout << e << ' ';
	return 0;
}
