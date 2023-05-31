#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<pair<int, int>>> route(n + 1);
		int res = 0;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			route[a].emplace_back(make_pair(b, i));
			route[b].emplace_back(make_pair(a, i));
		}
		queue<pair<int, int>> q;
		vector<bool> vist(n + 1, false);
		q.push(make_pair(1, 0));
		vist[1] = true;
		for (;;) {
			queue<pair<int, int>> next_round;
			if (q.empty()) break;
			while (!q.empty()) {
				auto p = q.front();
				q.pop();
				auto cur_node = p.first, cur_step = p.second;
				for (auto child : route[cur_node]) {
					if (vist[child.first]) continue;
					vist[child.first] = true;
					if (child.second > cur_step)
						q.push(make_pair(child.first, child.second));
					else
						next_round.push(
						  make_pair(child.first, child.second));
				}
			}
			res += 1;
			swap(q, next_round);
		}
		cout << res << "\n";
	}
	return 0;
}