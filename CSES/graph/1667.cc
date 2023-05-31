#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> route(n + 1);
	while (m--) {
		cin >> a >> b;
		route[a].emplace_back(b);
		route[b].emplace_back(a);
	}
	vector<int> prev_record(n + 1);
	vector<bool> vist(n + 1, false);
	queue<int> q;
	q.push(1);
	vist[1] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto child : route[cur]) {
			if (vist[child] == false) {
				vist[child] = true;
				q.push(child);
				prev_record[child] = cur;
			}
		}
	}
	if (prev_record[n] == 0) cout << "IMPOSSIBLE\n";
	else {
		vector<int> res = {n};
		auto node = n;
		while (prev_record[node]) {
			res.emplace_back(prev_record[node]);
			node = prev_record[node];
		}
		cout << res.size() << "\n";
		while (!res.empty()) {
			cout << res.back() << " ";
			res.pop_back();
		}
	}
	return 0;
}